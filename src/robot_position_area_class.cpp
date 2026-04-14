#include "robot_gui/robot_position_area_class.h"
#include <iomanip>
#include <sstream>

CVUIROSRobotPositionArea::CVUIROSRobotPositionArea(ros::NodeHandle *nh) {

  this->x_pos = "";
  this->z_pos = "";
  this->z_pos = "";

  this->sub_ = nh->subscribe<nav_msgs::Odometry>(
      "/cooper_1/odom", 20, &CVUIROSRobotPositionArea::odom_callback, this);
}

void CVUIROSRobotPositionArea::odom_callback(
    const nav_msgs::Odometry::ConstPtr &msg) {

  std::ostringstream oss;

  oss << std::fixed << std::setprecision(2) << msg->pose.pose.position.x;
  this->x_pos = oss.str();

  // Reset
  oss.str("");
  oss.clear();

  oss << std::fixed << std::setprecision(2) << msg->pose.pose.position.y;
  this->y_pos = oss.str();

  // Reset
  oss.str("");
  oss.clear();

  oss << std::fixed << std::setprecision(2) << msg->pose.pose.position.z;
  this->z_pos = oss.str();

  // Reset
  oss.str("");
  oss.clear();

  /*this->x_pos =
      (std::to_string(msg->pose.pose.position.x).substr(0, 4)).c_str();
  this->y_pos =
      (std::to_string(msg->pose.pose.position.y).substr(0, 4)).c_str();
  this->z_pos =
      (std::to_string(msg->pose.pose.position.z).substr(0, 4)).c_str();*/
}

void CVUIROSRobotPositionArea::draw(cv::Mat &frame, const int &width) {

  // Robot Position Area Title
  cvui::printf(frame, 10, 630, 0.4, 0xffffff,
               "Estimated robot position based off odometry");

  // X Position Window
  cvui::window(frame, 10, 650, (width / 3 - 20), 120, "X");
  // Y Position Window
  cvui::window(frame, (width / 3 + 10), 650, (width / 3 - 20), 120, "Y");
  // Z Position Window
  cvui::window(frame, ((width / 3) * 2 + 10), 650, (width / 3 - 20), 120, "Z");

  // Show x position inside the window.
  cvui::printf(frame, 20, 710, 0.8, 0xffffff, this->x_pos.c_str());

  // Show Y position inside the window.
  cvui::printf(frame, (width / 3 + 20), 710, 0.8, 0xffffff,
               this->y_pos.c_str());

  // Show Z position inside the window.
  cvui::printf(frame, ((width / 3) * 2 + 20), 710, 0.8, 0xffffff,
               this->z_pos.c_str());
}