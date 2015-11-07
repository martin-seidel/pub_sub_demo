#include "ros/ros.h"
#include "std_msgs/Int32.h"
#include "std_msgs/String.h"

ros::Publisher send_str_pub;

void int32_callback(const std_msgs::Int32::ConstPtr& input_msg) {
  ROS_INFO("I heard: %i", input_msg->data);

  std_msgs::String output_msg;
  output_msg.data.append(input_msg->data, 'f');
  send_str_pub.publish(output_msg);

  ROS_DEBUG("send \"%s\"", output_msg.data.c_str());
}

int main(int argc, char** argv) {
  ros::init(argc, argv, "demo2_send_str");
  ros::NodeHandle roshandle;

  send_str_pub = roshandle.advertise<std_msgs::String>("str_topic", 10);

  ros::Subscriber int32_sub = roshandle.subscribe("int32_topic", 10, int32_callback);

  ros::spin();

  return 0;
}
