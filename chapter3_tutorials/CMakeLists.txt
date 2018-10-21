cmake_minimum_required(VERSION 2.8.3)
project(chapter3_tutorials)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  message_generation
  std_msgs
  geometry_msgs
  dynamic_reconfigure
  diagnostic_updater    # ada karena untuk example7.cpp
  sensor_msgs           # ada karena untuk example8.cpp
  cv_bridge             # ada karena untuk example8.cpp
  image_transport       # ada karena untuk example8.cpp
  sensor_msgs           # ada karena untuk example9.cpp
  pcl_conversions       # ada karena untuk example9.cpp
)

find_package(OpenCV)          # ada karena untuk example8.cpp
find_package(PCL REQUIRED)    # ada karena untuk example9.cpp

add_service_files(FILES SetSpeed.srv)     #di panggil untuk example4_ dan example5_

generate_messages(DEPENDENCIES std_msgs)

generate_dynamic_reconfigure_options(cfg/DynamicParam.cfg)    #ini ada karena untuk example6

catkin_package(
  CATKIN_DEPENDS
    roscpp
    std_msgs
    geometry_msgs
    message_runtime
    #dynamic_reconfigure
    #diagnostic_updater
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(example1 src/example1.cpp)
target_link_libraries(example1 ${catkin_LIBRARIES})

add_executable(example2 src/example2.cpp)
target_link_libraries(example2 ${catkin_LIBRARIES})

add_executable(example3 src/example3.cpp)
target_link_libraries(example3 ${catkin_LIBRARIES})

add_executable(example4_ src/example4_.cpp)
target_link_libraries(example4_ ${catkin_LIBRARIES})

add_executable(example5_ src/example5_.cpp)
target_link_libraries(example5_ ${catkin_LIBRARIES})

add_executable(example6 src/example6.cpp)
target_link_libraries(example6 ${catkin_LIBRARIES})

add_executable(example7 src/example7.cpp)
target_link_libraries(example7 ${catkin_LIBRARIES})

#add_executable(example8 src/example8.cpp)
#target_link_libraries(example8 ${catkin_LIBRARIES})

add_executable(example9 src/example9.cpp)
target_link_libraries(example9 ${catkin_LIBRARIES})


install(TARGETS
  example1 example2 example3 example4_ example5_
  example6 example7 example9
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)
