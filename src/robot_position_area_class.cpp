#include "robot_gui/robot_position_area_class.h"
#include "geometry_msgs/Twist.h"
#include "robot_gui/utils.h"

CVUIROSRobotPositionArea::CVUIROSRobotPositionArea(ros::NodeHandle *nh) {

  this->x_pos = "";
  this->y_pos = "";
  this->z_pos = "";

  this->pub_ = nh->advertise<nav_msgs::Odometry>("/odom", 10);
  this->sub_ = nh->subscribe<nav_msgs::Odometry>(
      "/cooper_1/odom", 20, &CVUIROSRobotPositionArea::odom_callback, this);
}

void CVUIROSRobotPositionArea::odom_callback(
    const nav_msgs::Odometry::ConstPtr &msg) {

  this->pub_.publish(*msg);

  this->x_pos = Utils::double_to_string_n_deci(msg->pose.pose.position.x, 2);
  this->y_pos = Utils::double_to_string_n_deci(msg->pose.pose.position.y, 2);
  this->z_pos = Utils::double_to_string_n_deci(msg->pose.pose.position.z, 2);
}

void CVUIROSRobotPositionArea::draw(cv::Mat &frame, const int &width) {

  // Robot Position Area Title
  cvui::printf(frame, 10, 505, 0.4, 0xffffff,
               "Estimated robot position based off odometry");

  // X Position Window
  cvui::window(frame, 10, 525, (width / 3 - 20), 120, "X");
  // Y Position Window
  cvui::window(frame, (width / 3 + 10), 525, (width / 3 - 20), 120, "Y");
  // Z Position Window
  cvui::window(frame, ((width / 3) * 2 + 10), 525, (width / 3 - 20), 120, "Z");

  // Show x position inside the window.
  cvui::printf(frame, 20, 585, 0.8, 0xffffff, this->x_pos.c_str());

  // Show Y position inside the window.
  cvui::printf(frame, (width / 3 + 20), 585, 0.8, 0xffffff,
               this->y_pos.c_str());

  // Show Z position inside the window.
  cvui::printf(frame, ((width / 3) * 2 + 20), 585, 0.8, 0xffffff,
               this->z_pos.c_str());
}