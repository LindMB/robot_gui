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
};