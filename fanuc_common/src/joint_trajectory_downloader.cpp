/*
 * Software License Agreement (BSD License)
 *
 * Copyright (c) 2011, Southwest Research Institute
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 	* Redistributions of source code must retain the above copyright
 * 	notice, this list of conditions and the following disclaimer.
 * 	* Redistributions in binary form must reproduce the above copyright
 * 	notice, this list of conditions and the following disclaimer in the
 * 	documentation and/or other materials provided with the distribution.
 * 	* Neither the name of the Southwest Research Institute, nor the names
 *	of its contributors may be used to endorse or promote products derived
 *	from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include <fanuc_common/joint_trajectory_downloader.h>
#include <simple_message/joint_traj_pt.h>
#include <simple_message/messages/joint_traj_pt_message.h>
#include <simple_message/smpl_msg_connection.h>

using namespace industrial::smpl_msg_connection;
using namespace industrial::joint_data;
using namespace industrial::joint_traj_pt;
using namespace industrial::joint_traj_pt_message;
using namespace industrial::simple_message;


namespace fanuc_common
{
namespace joint_trajectory_downloader
{
JointTrajectoryDownloader::JointTrajectoryDownloader()
{
}

JointTrajectoryDownloader::JointTrajectoryDownloader(ros::NodeHandle &n,
		SmplMsgConnection* robotConnecton) : node_(n)
{
	ROS_INFO("Constructor joint trajectory downloader node");

	this->sub_joint_trajectory_ = this->node_.subscribe("command",
			0, &JointTrajectoryDownloader::jointTrajectoryCB, this);
	this->robot_ = robotConnecton;
  this->robot_->makeConnect();
	ROS_INFO("Joint trajectory downloader node initialized");
}

JointTrajectoryDownloader::~JointTrajectoryDownloader()
{  
	trajectoryStop();
	this->sub_joint_trajectory_.shutdown();
}

void JointTrajectoryDownloader::jointTrajectoryCB(
		const trajectory_msgs::JointTrajectoryConstPtr &msg)
{
	ROS_INFO("Receiving joint trajectory message");

	// TBD: re-enable in a more generic fashion?
	//if (!checkTrajectory(msg))
	//{
	//	ROS_ERROR("Joint trajectory check failed, trajectory not downloaded");
	//	return;
	//}
  
	std::vector<double> joint_velocity_limits;
	std::vector<trajectory_msgs::JointTrajectoryPoint> points(msg->points);
  
	// TBD: re-enable velocity scaling
	//if (!getVelocityLimits("robot_description", msg, joint_velocity_limits))
	//{
	//	ROS_ERROR("Failed to get joint velocity limits");
	//	return;
	//}

	// Trajectory download requires at least two points (START/END)
        if (points.size() < 2)
          points.push_back(trajectory_msgs::JointTrajectoryPoint(points[0]));

  if (!this->robot_->isConnected())
  {
    ROS_WARN("Attempting robot reconnection");
    this->robot_->makeConnect();
  }
  
  ROS_INFO("Sending trajectory points, size: %d", points.size());

	for (int i = 0; i < points.size(); i++)
	{
		ROS_INFO("Sending joints trajectory point[%d]", i);

		JointTrajPt jPt;
		JointTrajPtMessage jMsg;
		SimpleMessage topic;

		// Performing a manual copy of the joint velocities in order to send them
    // to the utility function.  Passing the pt data members doesn't seem to
    // work.
    std::vector<double> joint_velocities(0.0);
    double velocity =0 ;
    joint_velocities.resize(msg->joint_names.size(), 0.0);
    for (int j = 0; j < joint_velocities.size(); j++)
    {
      joint_velocities[j] = points[i].velocities[j];
    }

    ROS_DEBUG("Joint velocities copied");
    // TBD: restore joint-velocity scaling
    //velocity = toMotomanVelocity(joint_velocity_limits, joint_velocities);
    velocity = 0.20;  // TBD: hardcode for now

    jPt.setVelocity(velocity);

		// The first and last sequence values must be given a special sequence
		// value
		if (0 == i)
		{
			ROS_DEBUG("First trajectory point, setting special sequence value");
			jPt.setSequence(SpecialSeqValues::START_TRAJECTORY_DOWNLOAD);
		}
		else if (points.size() - 1 == i)
		{
			ROS_DEBUG("Last trajectory point, setting special sequence value");
			jPt.setSequence(SpecialSeqValues::END_TRAJECTORY);
		}
		else
		{
			jPt.setSequence(i);
		}

		// Copy position data to local variable
		JointData data;
		for (int j = 0; j < msg->joint_names.size(); j++)
		{
			data.setJoint(j, points[i].positions[j]);
		}

		// Initialize joint trajectory message
		jPt.setJointPosition(data);
		jMsg.init(jPt);
		jMsg.toTopic(topic);

		ROS_DEBUG("Sending joint trajectory point");
		if (this->robot_->sendMsg(topic))
		{
			ROS_INFO("Point[%d] sent to controller", i);
		}
		else
		{
			ROS_WARN("Failed sent joint point, skipping point");
		}
	}
}

void JointTrajectoryDownloader::trajectoryStop()
{
  JointTrajPtMessage jMsg;
  SimpleMessage msg;
  SimpleMessage reply;

  ROS_INFO("Joint trajectory downloader: entering stopping state");
  jMsg.point_.setSequence(SpecialSeqValues::STOP_TRAJECTORY);
  jMsg.toRequest(msg);
  ROS_DEBUG("Sending stop command");
  this->robot_->sendAndReceiveMsg(msg, reply);
  ROS_DEBUG("Stop command sent");
}

} //joint_trajectory_handler
} //fanuc_common

