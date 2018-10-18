#include <ros/ros.h>
#include <ros/console.h>

int main(int argc, char **argv) {
  ros::init(argc, argv, "example3");
  ros::NodeHandle n;
  ros::Rate rate(1);
  while (ros::ok()) {
    ROS_DEBUG_STREAM("1 Debug Message.");
    ROS_INFO_STREAM("2 INFO Message.");
    ROS_WARN_STREAM("3 WARN Message.");
    ROS_ERROR_STREAM("4 Error message.");
    ROS_FATAL_STREAM("5 FATAL message.");
    ROS_INFO_STREAM_NAMED("named_msg", "6 INFO named message");
    ROS_INFO_STREAM_THROTTLE(2, "7 Info throttle message.");

    ros::spinOnce();
    rate.sleep();
  }
  return EXIT_SUCCESS;
}
