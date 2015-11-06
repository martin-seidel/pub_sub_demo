#include "ros/ros.h"

int main(int argc, char** argv) {
  ros::init(argc, argv, "pub_sub_demo");
  ros::NodeHandle roshandle;

  ROS_INFO("running");

  ros::spin();

  return 0;
}
