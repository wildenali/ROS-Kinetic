// Penerima data
#include "ros/ros.h"
#include "std_msgs/String.h"

void chatterCallback(const std_msgs::String::ConstPtr& msg) {
  ROS_INFO("yeah : [%s]", msg->data.c_str());
}

int main(int argc, char **argv) {
  ros::init(argc, argv, "example1_b");
  ros::NodeHandle n;
  ros::Subscriber sub = n.subscribe("message",1000, chatterCallback);
  ros::spin();
  return 0;
}
