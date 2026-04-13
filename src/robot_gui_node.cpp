#include "robot_gui/main_window_class.h"
#include <ros/ros.h>

int main(int argc, char **argv) {
  ros::init(argc, argv, "robot_gui_node");
  ros::NodeHandle nh;
  CVUIROSMainWindow mw = CVUIROSMainWindow(&nh);
  mw.run();
  return 0;
}