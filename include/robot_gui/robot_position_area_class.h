#pragma once

#include "robot_gui/cvui.h"
#include <opencv2/opencv.hpp>

#include <nav_msgs/Odometry.h>
#include <ros/ros.h>
#include <string>

class CVUIROSRobotPositionArea {

public:
  CVUIROSRobotPositionArea(ros::NodeHandle *nh);

  void draw(cv::Mat &frame, const int &width);

  ~CVUIROSRobotPositionArea() = default;

private:
  ros::Subscriber sub_;
  std::string x_pos;
  std::string y_pos;
  std::string z_pos;

  void odom_callback(const nav_msgs::Odometry::ConstPtr &msg);
};