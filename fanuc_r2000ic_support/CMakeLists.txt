cmake_minimum_required(VERSION 3.0.2)

project(fanuc_r2000ic_support)

find_package(catkin REQUIRED)

catkin_package()

if (CATKIN_ENABLE_TESTING)
  find_package(roslaunch REQUIRED)
  roslaunch_add_file_check(tests/roslaunch_test_r2000ic125l.xml)
  roslaunch_add_file_check(tests/roslaunch_test_r2000ic165f.xml)
  roslaunch_add_file_check(tests/roslaunch_test_r2000ic210f.xml)
  roslaunch_add_file_check(tests/roslaunch_test_r2000ic210l.xml)
  roslaunch_add_file_check(tests/roslaunch_test_r2000ic270f.xml)
endif()

install(DIRECTORY config launch meshes urdf
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION})

install(FILES readme.md DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION})
