cmake_minimum_required(VERSION 2.8.3)

project(fanuc_lrmate200id_support)

find_package(catkin REQUIRED)

catkin_package()

if (CATKIN_ENABLE_TESTING)
  find_package(roslaunch REQUIRED)
  roslaunch_add_file_check(tests/roslaunch_test.xml
    DEPENDENCIES
      # not nice, but industrial_robot_client doesn't prefix its targets
      joint_trajectory_action
      fanuc_driver_robot_state
      fanuc_driver_robot_state_bswap
      fanuc_driver_motion_streaming_interface
      fanuc_driver_motion_streaming_interface_bswap)
endif()

install(DIRECTORY config launch meshes urdf
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION})

install(FILES readme.md DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION})
