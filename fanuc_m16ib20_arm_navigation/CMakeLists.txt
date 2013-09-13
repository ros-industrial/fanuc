cmake_minimum_required(VERSION 2.8.3)

project(fanuc_m16ib20_arm_navigation)

find_package(catkin REQUIRED)

catkin_package()

foreach(dir config launch)
   install(DIRECTORY ${dir}/
      DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}/${dir})
endforeach(dir)
