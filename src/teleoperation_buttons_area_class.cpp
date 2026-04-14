#include "robot_gui/teleoperation_buttons_area_class.h"

CVUIROSTeleopButtonsArea::CVUIROSTeleopButtonsArea(ros::NodeHandle *nh) {

  this->current_linear_x = 0.0;
  this->current_angular_z = 0.0;

  this->pub_ = nh->advertise<geometry_msgs::Twist>("/cooper_1/cmd_vel", 10);
  this->sub_ = nh->subscribe<geometry_msgs::Twist>(
      "/cooper_1/cmd_vel", 20, &CVUIROSTeleopButtonsArea::cmd_vel_callback,
      this);
}

void CVUIROSTeleopButtonsArea::cmd_vel_callback(
    const geometry_msgs::Twist::ConstPtr &msg) {
  this->current_linear_x = msg->linear.x;
  this->current_angular_z = msg->angular.z;
}

void CVUIROSTeleopButtonsArea::draw(cv::Mat &frame, const int &width) {

  // cvui::button(frame, x, y, largeur, hauteur, "Texte")
  if (cvui::button(frame, 10, (320 + 10), ((width / 3) - 20), 100, "Left")) {
    ROS_INFO("Button Left clicked...");

    geometry_msgs::Twist msg;

    msg.linear.x = this->current_linear_x;
    msg.angular.z = this->current_angular_z + angular_z_step;

    this->pub_.publish(msg);
  }

  if (cvui::button(frame, ((width / 3) + 10), 210, ((width / 3) - 20), 100,
                   "Forward")) {
    ROS_INFO("Button Forward clicked...");

    geometry_msgs::Twist msg;

    msg.linear.x = this->current_linear_x + linear_x_step;
    msg.angular.z = this->current_angular_z;

    this->pub_.publish(msg);
  }

  if (cvui::button(frame, ((width / 3) + 10), (320 + 10), ((width / 3) - 20),
                   100, "Stop")) {
    ROS_INFO("Button Stop clicked...");

    geometry_msgs::Twist msg;

    msg.linear.x = 0.0;
    msg.angular.z = 0.0;

    this->pub_.publish(msg);
  }

  if (cvui::button(frame, (((width / 3) * 2) + 10), (320 + 10),
                   ((width / 3) - 20), 100, "Right")) {
    ROS_INFO("Button Right clicked...");

    geometry_msgs::Twist msg;

    msg.linear.x = this->current_linear_x;
    msg.angular.z = this->current_angular_z - angular_z_step;

    this->pub_.publish(msg);
  }

  if (cvui::button(frame, ((width / 3) + 10), (420 + 30), ((width / 3) - 20),
                   100, "Backward")) {
    ROS_INFO("Button Backward clicked...");

    geometry_msgs::Twist msg;

    msg.linear.x = this->current_linear_x - linear_x_step;
    msg.angular.z = this->current_angular_z;

    this->pub_.publish(msg);
  }

  // Linear Velocity Window
  // cvui::window(frame, x, y, width, height, "Text");
  cvui::window(frame, 10, 570, (width / 2 - 20), 50, "Linear Velocity");

  // Show linear velocity inside the window.
  cvui::printf(
      frame, 30, 595, 0.6, 0xff0000,
      ((std::to_string(this->current_linear_x).substr(0, 4) + " m/s").c_str()));

  // Angular Velocity Window
  cvui::window(frame, (width / 2), 570, (width / 2 - 20), 50,
               "Angular Velocity");

  // Show angular velocity inside the window.
  cvui::printf(
      frame, (width / 2 + 20), 595, 0.6, 0xff0000,
      ((std::to_string(this->current_angular_z).substr(0, 4) + " rad/s")
           .c_str()));
}
