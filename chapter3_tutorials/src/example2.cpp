#include <ros/ros.h>
#include <ros/console.h>

int main(int argc, char **argv) {
  ros::init(argc, argv, "example2");
  ros::NodeHandle n;
  const couble val = 3.14;

  // Basic Messages:
  ROS_INFO("my info nih");
  ROS_INFO("cek lagi ini pi: %f", val);
  ROS_INFO_STREAM("my info stream message with argument: " << val);

  // Named messages:
  ROS_INFO_STREAM_NAMED(
    "named_msg",
    "My named INFO stream message; val = " << val
  );

  // Conditional messages:
  ROS_INFO_STREAM_COND(
    val < 0.,
    "My conditional INFO stream message; val (" << val << ") < 0"
  );
  ROS_INFO_STREAM_COND(
    val >= 0.,
    "My conditional INFO stream message; val(" << val << ") >= 0"
  );

  // Conditional Named Messages
  ROS_INFO_STREAM_COND_NAMED(
    val < 0., "cond_named_msg",
    "my cinditional INFO stream message; val(" << val << ") < 0"
  );
  ROS_INFO_STREAM_COND_NAMED(
    val >= 0., "cond_named_msg",
    "my cinditional INFO stream message; val(" << val << ") >= 0"
  );

  // Filtered message:
  struct MyLowerFilter : public ros::console::FilterBase{
    MyLowerFilter(const double& val) : value(val){}

      inline virtual bool isEnable(){
        return value < 0.;
      }
      double value;
    };

  struct MyGreaterEqualFilter : public ros::console::FilterBase {
    MyGreaterEqualFilter(const double& val) : value(val){}

    inline virtual bool isEnable(){
      return value >= 0;
    }
    double value;
  };

  MyLowerFilter filter_lower(val);
  MyGreaterEqualFilter filter_greater_equal(val);

  ROS_INFO_STREAM_FILTER(
    &filter_lower,
    "My filter INFO stream message; val(" << val << ") < 0"
  );
  ROS_INFO_STREAM_FILTER(
    &filter_greater_equal,
    "My filter INFO stream message; val(" << val << ") >= 0"
  )

  // Once message:
  for (int i = 0; i < 10; ++i) {
    ROS_INFO_STREAM_ONCE(
      "My one INFO stream message; i = " << i
    );
  }

  // Throttle message:
  for (int i = 0; i < 10; ++i) {
    ROS_INFO_STREAM_THROTTLE(
      2,
      "My throttle INFO stream message; i = " << i
    );
    ros::Duration(1).sleep();
  }

  ros::spinOnce();

  return EXIT_SUCCESS;
}
