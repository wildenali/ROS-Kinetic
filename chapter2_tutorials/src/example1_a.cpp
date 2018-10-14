// Pengirim data
#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>
// chatterCallback
int main(int argc, char **argv) {
  /* code */
  ros::init(argc, argv, "example1_a");
  ros::NodeHandle n;
  ros::Publisher chatter_pub = n.advertise<std_msgs::String>("message", 1000);
  ros::Rate loop_rate(10);
  while (ros::ok()) {
    std_msgs::String msg;
    std::stringstream ss;
    ss << "saya pengirim data";
    msg.data = ss.str();
    // ROS_INFO("%s", msg.data.c_str());
    chatter_pub.publish(msg);
    loop_rate.sleep();
  }
  return 0;
}
// test github
