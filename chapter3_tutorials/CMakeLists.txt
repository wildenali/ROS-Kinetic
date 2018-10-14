cmake_minimum_required(VERSION 2.8.3)
project(chapter3_tutorials)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  message_generation
  std_msgs
)

generate_messages(DEPENDENCIES std_msgs)

catkin_package(
  CATKIN_DEPENDS
    roscpp
    std_msgs
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(example1 src/example1.cpp)
target_link_libraries(example1 ${catkin_LIBRARIES})

add_executable(example2 src/example1.cpp)
target_link_libraries(example2 ${catkin_LIBRARIES})
