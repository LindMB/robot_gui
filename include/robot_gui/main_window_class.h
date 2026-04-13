#pragma once

#include "robot_gui/general_info_area_class.h"
#include <ros/ros.h>

class CVUIROSMainWindow {
public:
  CVUIROSMainWindow(ros::NodeHandle *nh);

  void run();

  ~CVUIROSMainWindow() = default;

private:
  const int height = 300;
  const int width = 500;
  const std::string WINDOW_NAME = "Robot Cooper Simulator";

  CVUIROSGeneralInfoArea general_info_area;
};