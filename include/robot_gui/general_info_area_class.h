#pragma once

#include "robot_gui/cvui.h"
#include <opencv2/opencv.hpp>

#include "robotinfo_msgs/RobotInfo10Fields.h"
#include <ros/ros.h>

class CVUIROSGeneralInfoArea {

public:
  CVUIROSGeneralInfoArea(ros::NodeHandle *nh);

  void draw(cv::Mat &frame, const int &width);

  ~CVUIROSGeneralInfoArea() = default;

private:
  ros::Subscriber sub_;

  std::string data_field_01;
  std::string data_field_02;
  std::string data_field_03;
  std::string data_field_04;
  std::string data_field_05;
  std::string data_field_06;
  std::string data_field_07;
  std::string data_field_08;
  std::string data_field_09;
  std::string data_field_10;

  void msgCallback(const robotinfo_msgs::RobotInfo10Fields::ConstPtr &msg);
};