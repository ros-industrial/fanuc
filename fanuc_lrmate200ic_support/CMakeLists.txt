cmake_minimum_required(VERSION 3.0.2)

project(fanuc_lrmate200ic_support)

find_package(catkin REQUIRED)

catkin_package()

if (CATKIN_ENABLE_TESTING)
  find_package(roslaunch REQUIRED)
  roslaunch_add_file_check(tests/roslaunch_test.xml)
endif()

install(DIRECTORY config launch meshes urdf
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION})

install(FILES readme.md DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION})
