#pragma once

#include "robot_gui/cvui.h"
#include <opencv2/opencv.hpp>

#include <ros/ros.h>
#include <string>

class CVUIROSDistanceTrackerArea {
public:
  CVUIROSDistanceTrackerArea(ros::NodeHandle *nh);

  void draw(cv::Mat &frame, const int &width);

  ~CVUIROSDistanceTrackerArea() = default;

private:
  ros::Subscriber sub_;
  ros::ServiceClient get_distance_srv_client;
  ros::ServiceClient reset_distance_srv_client;
  std::string distance;
};