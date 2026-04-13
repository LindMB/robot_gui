#pragma once

#define CVUI_IMPLEMENTATION
#include "robot_gui/cvui.h"
#include "robotinfo_msgs/RobotInfo10Fields.h"
#include <opencv2/opencv.hpp>
#include <ros/ros.h>

class CVUIROSGeneralInfoArea {
public:
  CVUIROSGeneralInfoArea(ros::NodeHandle *nh);

  void run();

  ~CVUIROSGeneralInfoArea() = default;

private:
  ros::Subscriber sub_;
  std::string topic_name;

  std::string data_field_01;
  std::string data_field_02;
  std::string data_field_03;
  std::string data_field_04;
  std::string data_field_05;
  std::string data_field_06;
  std::string data_field_07;
  std::string data_field_08;

  const int height = 300;
  const int width = 500;
  const std::string WINDOW_NAME = "Robot Cooper Simulator";

  void msgCallback(const robotinfo_msgs::RobotInfo10Fields::ConstPtr &msg);
};