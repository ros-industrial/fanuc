cmake_minimum_required(VERSION 2.4.6)
include($ENV{ROS_ROOT}/core/rosbuild/rosbuild.cmake)

rosbuild_init()

# The definition is copied from the CMakeList for the simple_message package.
add_definitions(-DLINUXSOCKETS=1)  #build using LINUX SOCKETS libraries

#set the default path for built executables to the "bin" directory
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
#set the default path for built libraries to the "lib" directory
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

# Little Endian Fanuc specific robot state node
rosbuild_add_executable(robot_state
    src/fanuc_robot_state_node.cpp
    src/fanuc_utils.cpp)
target_link_libraries(robot_state industrial_robot_client)

# Little Endian Fanuc specific motion streaming interface
rosbuild_add_executable(motion_streaming_interface
    src/fanuc_joint_streamer_node.cpp
    src/fanuc_utils.cpp)
target_link_libraries(motion_streaming_interface
    industrial_robot_client)

# Big Endian Fanuc specific robot state node
rosbuild_add_executable(robot_state_bswap 
    src/fanuc_robot_state_node.cpp
    src/fanuc_utils.cpp)
target_link_libraries(robot_state_bswap industrial_robot_client_bswap)

# Big Endian Fanuc specific motion streaming interface
rosbuild_add_executable(motion_streaming_interface_bswap
    src/fanuc_joint_streamer_node.cpp
    src/fanuc_utils.cpp)
target_link_libraries(motion_streaming_interface_bswap
    industrial_robot_client_bswap)
