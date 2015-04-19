cmake_minimum_required(VERSION 2.8.3)
project(fanuc_lrmate200ic_moveit_plugins)

find_package(catkin REQUIRED COMPONENTS
  moveit_core
  pluginlib
  roscpp
  tf_conversions
)

include_directories(${catkin_INCLUDE_DIRS})

find_package(LAPACK REQUIRED)

catkin_package(
  LIBRARIES
  CATKIN_DEPENDS
    moveit_core
    pluginlib
    roscpp
    tf_conversions
)

add_subdirectory(lrmate200ic_kinematics)
add_subdirectory(lrmate200ic5f_kinematics)
add_subdirectory(lrmate200ic5h_kinematics)
add_subdirectory(lrmate200ic5l_kinematics)

install(FILES readme.md DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION})
