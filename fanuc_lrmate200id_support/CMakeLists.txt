cmake_minimum_required(VERSION 2.8.3)

project(fanuc_lrmate200id_support)

find_package(catkin REQUIRED)

catkin_package()

foreach(dir config launch meshes urdf)
   install(DIRECTORY ${dir}/
      DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}/${dir})
endforeach(dir)
