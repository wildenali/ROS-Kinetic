cmake_minimum_required(VERSION 2.8.3)
project(robot1_description)

find_package(catkin REQUIRED COMPONENTS
  fake_localization
  ## laser_filters    ## ini masih bermasalah saat di catkin_make
  map_server
  ## robot_state_publisher
  roscpp
  rospy
  std_msgs
  tf
  urdf
  xacro
)

catkin_package(
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

## add_executable(state_publisher_tutorials src/state_publisher.cpp)

## target_link_libraries(state_publisher_tutorials
##   ${catkin_LIBRARIES}
## )
