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

  this->topic_name = "robot_info";
  this->sub_ = nh->subscribe<robotinfo_msgs::RobotInfo10Fields>(
      this->topic_name, 5, &CVUIROSGeneralInfoArea::msgCallback, this);
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
}

void CVUIROSGeneralInfoArea::draw(cv::Mat &frame, const int &width) {

  // Create window at (20 x-axis, 20 y-axis) with size (width-40)x100 (width x
  // height) and title
  cvui::window(frame, 20, 20, (width - 20 * 2), 190, "General Information");

  // Show general robot information inside the window.
  cvui::printf(frame, 30, 45, 0.4, 0xffffff, this->data_field_01.c_str());
  cvui::printf(frame, 30, 65, 0.4, 0xffffff, this->data_field_02.c_str());
  cvui::printf(frame, 30, 85, 0.4, 0xffffff, this->data_field_03.c_str());
  cvui::printf(frame, 30, 105, 0.4, 0xffffff, this->data_field_04.c_str());
  cvui::printf(frame, 30, 125, 0.4, 0xffffff, this->data_field_05.c_str());
  cvui::printf(frame, 30, 145, 0.4, 0xffffff, this->data_field_06.c_str());
  cvui::printf(frame, 30, 165, 0.4, 0xffffff, this->data_field_07.c_str());
  cvui::printf(frame, 30, 185, 0.4, 0xffffff, this->data_field_08.c_str());
}