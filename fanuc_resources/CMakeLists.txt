cmake_minimum_required(VERSION 3.0.2)

project(fanuc_resources)

find_package(catkin REQUIRED)

catkin_package()

install(DIRECTORY urdf
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION})

install(FILES readme.md DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION})
