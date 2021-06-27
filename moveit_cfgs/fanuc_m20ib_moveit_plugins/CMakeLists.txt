cmake_minimum_required(VERSION 2.8.12)
project(fanuc_m20ib_moveit_plugins)

find_package(catkin REQUIRED COMPONENTS
  moveit_core
  pluginlib
  roscpp
  tf_conversions
)

# enable C++11 if needed for MoveIt on Kinetic
if ("${moveit_core_VERSION}" VERSION_GREATER "0.9.0")
  add_definitions(-std=c++11)
endif()

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

add_subdirectory(m20ib25_kinematics)

install(FILES readme.md DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION})
