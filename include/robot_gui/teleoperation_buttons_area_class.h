#pragma once

#include "robot_gui/cvui.h"
#include <opencv2/opencv.hpp>
#include <ros/ros.h>

class CVUIROSTeleopButtonsArea {

public:
  CVUIROSTeleopButtonsArea(ros::NodeHandle *nh);

  void draw(cv::Mat &frame, const int &width);

  ~CVUIROSTeleopButtonsArea() = default;

private:
  ros::Publisher pub_;
  const double linear_x_step = 0.2;
  const double angular_z_step = 0.2;
  double current_linear_x;
  double current_angular_z;
};