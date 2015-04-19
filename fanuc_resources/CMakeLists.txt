cmake_minimum_required(VERSION 2.8.3)

project(fanuc_resources)

find_package(catkin REQUIRED)

catkin_package()

foreach(dir urdf)
  install(DIRECTORY ${dir}/
    DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}/${dir})
endforeach()

install(FILES readme.md DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION})
