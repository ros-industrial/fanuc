cmake_minimum_required(VERSION 3.0.2)

project(fanuc_driver)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# let industrial_robot_client pull in all other dependencies
find_package(catkin REQUIRED COMPONENTS industrial_robot_client)

catkin_package(
  CATKIN_DEPENDS industrial_robot_client
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)


# non-swapping Fanuc specific robot state node
add_executable(${PROJECT_NAME}_robot_state
  src/fanuc_robot_state_node.cpp
  src/fanuc_utils.cpp)
target_link_libraries(${PROJECT_NAME}_robot_state
  industrial_robot_client
  simple_message
  ${catkin_LIBRARIES})
set_target_properties(${PROJECT_NAME}_robot_state
  PROPERTIES OUTPUT_NAME robot_state
  PREFIX "")
target_compile_definitions(
  ${PROJECT_NAME}_robot_state
  PRIVATE
  ${industrial_robot_client_DEFINITIONS})


# byte-swapping Fanuc specific robot state node
add_executable(${PROJECT_NAME}_robot_state_bswap
  src/fanuc_robot_state_node.cpp
  src/fanuc_utils.cpp)
target_link_libraries(${PROJECT_NAME}_robot_state_bswap
  industrial_robot_client_bswap
  simple_message_bswap
  ${catkin_LIBRARIES})
set_target_properties(${PROJECT_NAME}_robot_state_bswap
  PROPERTIES OUTPUT_NAME robot_state_bswap
  PREFIX "")
target_compile_definitions(
  ${PROJECT_NAME}_robot_state_bswap
  PRIVATE
  ${industrial_robot_client_bswap_DEFINITIONS})


# non-swapping Fanuc specific motion streaming interface
add_executable(${PROJECT_NAME}_motion_streaming_interface
  src/fanuc_joint_streamer_node.cpp
  src/fanuc_utils.cpp)
target_link_libraries(${PROJECT_NAME}_motion_streaming_interface
  industrial_robot_client
  simple_message
  ${catkin_LIBRARIES})
set_target_properties(${PROJECT_NAME}_motion_streaming_interface
  PROPERTIES OUTPUT_NAME motion_streaming_interface
  PREFIX "")
target_compile_definitions(
  ${PROJECT_NAME}_motion_streaming_interface
  PRIVATE
  ${industrial_robot_client_DEFINITIONS})


# byte-swapping Fanuc specific motion streaming interface
add_executable(${PROJECT_NAME}_motion_streaming_interface_bswap
  src/fanuc_joint_streamer_node.cpp
  src/fanuc_utils.cpp)
target_link_libraries(${PROJECT_NAME}_motion_streaming_interface_bswap
  industrial_robot_client_bswap
  simple_message_bswap
  ${catkin_LIBRARIES})
set_target_properties(${PROJECT_NAME}_motion_streaming_interface_bswap
  PROPERTIES OUTPUT_NAME motion_streaming_interface_bswap
  PREFIX "")
target_compile_definitions(
  ${PROJECT_NAME}_motion_streaming_interface_bswap
  PRIVATE
  ${industrial_robot_client_bswap_DEFINITIONS})


if (CATKIN_ENABLE_TESTING)
  find_package(roslaunch REQUIRED)

  set(rl_test_deps
    ${PROJECT_NAME}_robot_state
    ${PROJECT_NAME}_robot_state_bswap
    ${PROJECT_NAME}_motion_streaming_interface
    ${PROJECT_NAME}_motion_streaming_interface_bswap)

  if (TARGET joint_trajectory_action)
    # not nice, but industrial_robot_client doesn't prefix its targets
    list(APPEND rl_test_deps joint_trajectory_action)
  endif()

  roslaunch_add_file_check(tests/roslaunch_test.xml
    DEPENDENCIES ${rl_test_deps})
endif()


install(TARGETS
  ${PROJECT_NAME}_motion_streaming_interface
  ${PROJECT_NAME}_motion_streaming_interface_bswap

  ${PROJECT_NAME}_robot_state
  ${PROJECT_NAME}_robot_state_bswap

  DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

install(DIRECTORY karel launch tpe
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION})

install(FILES readme.md DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION})
