#include "robot_gui/general_info_area_class.h"
#include <ros/ros.h>

int main(int argc, char **argv) {
  ros::init(argc, argv, "robot_gui_node");
  ros::NodeHandle nh;
  CVUIROSGeneralInfoArea general_info_area = CVUIROSGeneralInfoArea(&nh);
  general_info_area.run();
  return 0;
}