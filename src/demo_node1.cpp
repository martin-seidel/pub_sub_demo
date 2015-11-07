#include "ros/ros.h"
#include "std_msgs/Int32.h"
#include "std_msgs/String.h"

void str_callback(const std_msgs::String::ConstPtr& input_msg) {
   ROS_INFO("%s", input_msg->data.c_str());
}

int main(int argc, char** argv) {
   ros::init(argc, argv, "demo1_send_int");
   ros::NodeHandle roshandle;

   ros::Subscriber str_sub = roshandle.subscribe("str_topic", 10, str_callback);

   ros::Publisher send_int_pub = roshandle.advertise<std_msgs::Int32>("int32_topic", 10);

   ros::Rate loop_rate(1);
   int count = 1;
   std_msgs::Int32 msg;

   while (ros::ok()) {
      msg.data = count;
      send_int_pub.publish(msg);
      ROS_DEBUG("count: %i", msg.data);

      if (count > 9) {
         count = 1;
      } else {
         count++;
      }

      ros::spinOnce();
      loop_rate.sleep();
   }

   return 0;
}
