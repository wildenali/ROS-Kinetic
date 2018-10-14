#include "ros/ros.h"
#include "chapter2_tutorials/chapter2_srv1.h"
#include <cstdlib>

int main(int argc, char **argv) {
  ros::init(argc, argv, "add_3_ints_client");
  if (argc != 4) {
    ROS_INFO("usage: add_3_ints_server A B C");
    return 1;
  }
  ros::NodeHandle n;
  ros::ServiceClient client = n.serviceClient<chapter2_tutorials::chapter2_srv1>("add_3_ints");  // namanya add_3_ints
  chapter2_tutorials::chapter2_srv1 srv;
  srv.request.A = atoll(argv[1]);
  srv.request.B = atoll(argv[2]);
  srv.request.C = atoll(argv[3]);
  if (client.call(srv)) {
    ROS_INFO("Sum: %1d", (long int)srv.response.sum);
  }
  else {
    ROS_ERROR("failed to call service add_3_ints");
    return 1;
  }
  return 0;
}


// 10. Setelah program ini dibuat, selanjutnya adalah
// 11. edit file CMakeList.txt dan tambahkan code seperti di bawah ini
/*
add_executable(example2_a src/example2_a.cpp)
add_executable(example2_b src/example2_b.cpp)

add_dependencies(example2_a chapter2_tutorials_generate_messages_cpp)
add_dependencies(example2_b chapter2_tutorials_generate_messages_cpp)
target_link_libraries(example2_a ${catkin_LIBRARIES})
target_link_libraries(example2_b ${catkin_LIBRARIES})
*/
