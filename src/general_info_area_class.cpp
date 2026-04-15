#include "robot_gui/general_info_area_class.h"

CVUIROSGeneralInfoArea::CVUIROSGeneralInfoArea(ros::NodeHandle *nh) {

  this->data_field_01 = "";
  this->data_field_02 = "";
  this->data_field_03 = "";
  this->data_field_04 = "";
  this->data_field_05 = "";
  this->data_field_06 = "";
  this->data_field_07 = "";
  this->data_field_08 = "";
  this->data_field_09 = "";
  this->data_field_10 = "";

  this->sub_ = nh->subscribe<robotinfo_msgs::RobotInfo10Fields>(
      "robot_info", 5, &CVUIROSGeneralInfoArea::msgCallback, this);
}

void CVUIROSGeneralInfoArea::msgCallback(
    const robotinfo_msgs::RobotInfo10Fields::ConstPtr &msg) {

  this->data_field_01 = msg->data_field_01;
  this->data_field_02 = msg->data_field_02;
  this->data_field_03 = msg->data_field_03;
  this->data_field_04 = msg->data_field_04;
  this->data_field_05 = msg->data_field_05;
  this->data_field_06 = msg->data_field_06;
  this->data_field_07 = msg->data_field_07;
  this->data_field_08 = msg->data_field_08;
  this->data_field_09 = msg->data_field_09;
  this->data_field_10 = msg->data_field_10;
}

void CVUIROSGeneralInfoArea::draw(cv::Mat &frame, const int &width) {

  // Create window in frame at (20 x-axis, 10 y-axis) with size (width - 40)
  // x190 height) and title
  cvui::window(frame, 20, 10, (width - 20 * 2), 220, "General Information");

  // Show general robot information inside the window.
  cvui::printf(frame, 30, 35, 0.4, 0xffffff, this->data_field_01.c_str());
  cvui::printf(frame, 30, 55, 0.4, 0xffffff, this->data_field_02.c_str());
  cvui::printf(frame, 30, 75, 0.4, 0xffffff, this->data_field_03.c_str());
  cvui::printf(frame, 30, 95, 0.4, 0xffffff, this->data_field_04.c_str());
  cvui::printf(frame, 30, 115, 0.4, 0xffffff, this->data_field_05.c_str());
  cvui::printf(frame, 30, 135, 0.4, 0xffffff, this->data_field_06.c_str());
  cvui::printf(frame, 30, 155, 0.4, 0xffffff, this->data_field_07.c_str());
  cvui::printf(frame, 30, 175, 0.4, 0xffffff, this->data_field_08.c_str());
  cvui::printf(frame, 30, 195, 0.4, 0xffffff, this->data_field_09.c_str());
  cvui::printf(frame, 30, 215, 0.4, 0xffffff, this->data_field_10.c_str());
}