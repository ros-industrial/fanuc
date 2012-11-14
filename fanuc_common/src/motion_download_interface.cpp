/*
* Software License Agreement (BSD License) 
*
* Copyright (c) 2011, Yaskawa America, Inc.
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
*
*       * Redistributions of source code must retain the above copyright
*       notice, this list of conditions and the following disclaimer.
*       * Redistributions in binary form must reproduce the above copyright
*       notice, this list of conditions and the following disclaimer in the
*       documentation and/or other materials provided with the distribution.
*       * Neither the name of the Yaskawa America, Inc., nor the names 
*       of its contributors may be used to endorse or promote products derived
*       from this software without specific prior written permission.
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
#include <simple_message/socket/simple_socket.h>
#include <simple_message/socket/tcp_client.h>

using namespace industrial::simple_socket;

int main(int argc, char** argv)
{
  //const unsigned int IP_ARG_IDX = 1;
  ros::init(argc, argv, "joint_trajectory_handler");
  ros::NodeHandle node;
  std::string s;

  //if(argc != 1)  //Only one argument, the robot IP address is accepted
  if (node.getParam("robot_ip_address", s))
  {
    char* ip_addr = strdup(s.c_str());
    ROS_INFO("Motion download interface connecting to IP address: %s", ip_addr);
		
    industrial::tcp_client::TcpClient robot;
    robot.init(ip_addr, StandardSocketPorts::MOTION);
    fanuc_common::joint_trajectory_downloader::JointTrajectoryDownloader jtHandler(node, &robot);

	free(ip_addr);

    ros::spin();
  }
  else
  {
    //ROS_ERROR("Missing command line arguments, usage: motion_download_interface <robot ip address>");
    ROS_ERROR("Failed to get param 'robot_ip_address'");
  }

  return 0;
}
