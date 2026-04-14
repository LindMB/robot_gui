#include "robot_gui/teleoperation_buttons_area_class.h"
#include <geometry_msgs/Twist.h>
#include <ros/ros.h>

CVUIROSTeleopButtonsArea::CVUIROSTeleopButtonsArea(ros::NodeHandle *nh) {

  this->current_linear_x = 0.0;
  this->current_angular_z = 0.0;

  this->pub_ = nh->advertise<geometry_msgs::Twist>("/cooper_1/cmd_vel", 10);
}

void CVUIROSTeleopButtonsArea::draw(cv::Mat &frame, const int &width) {

  // cvui::button(frame, x, y, largeur, hauteur, "Texte")
  if (cvui::button(frame, 10, (320 + 10), ((width / 3) - 20), 100, "Left")) {
    ROS_INFO("Button Left clicked...");

    geometry_msgs::Twist msg;

    msg.linear.x = this->current_linear_x;
    msg.angular.z = this->current_angular_z + angular_z_step;

    this->current_linear_x = msg.linear.x;
    this->current_angular_z = msg.angular.z;

    this->pub_.publish(msg);

    ROS_INFO("Linear X: %f - Angular Z: %f", this->current_linear_x,
             this->current_angular_z);
  }

  if (cvui::button(frame, ((width / 3) + 10), 210, ((width / 3) - 20), 100,
                   "Forward")) {
    ROS_INFO("Button Forward clicked...");

    geometry_msgs::Twist msg;

    msg.linear.x = this->current_linear_x + linear_x_step;
    msg.angular.z = this->current_angular_z;

    this->current_linear_x = msg.linear.x;
    this->current_angular_z = msg.angular.z;

    this->pub_.publish(msg);

    ROS_INFO("Linear X: %f - Angular Z: %f", this->current_linear_x,
             this->current_angular_z);
  }

  if (cvui::button(frame, ((width / 3) + 10), (320 + 10), ((width / 3) - 20),
                   100, "Stop")) {
    ROS_INFO("Button Stop clicked...");

    geometry_msgs::Twist msg;

    msg.linear.x = 0.0;
    msg.angular.z = 0.0;

    this->current_linear_x = msg.linear.x;
    this->current_angular_z = msg.angular.z;

    this->pub_.publish(msg);

    ROS_INFO("Linear X: %f - Angular Z: %f", this->current_linear_x,
             this->current_angular_z);
  }

  if (cvui::button(frame, (((width / 3) * 2) + 10), (320 + 10),
                   ((width / 3) - 20), 100, "Right")) {
    ROS_INFO("Button Right clicked...");

    geometry_msgs::Twist msg;

    msg.linear.x = this->current_linear_x;
    msg.angular.z = this->current_angular_z - angular_z_step;

    this->current_linear_x = msg.linear.x;
    this->current_angular_z = msg.angular.z;

    this->pub_.publish(msg);

    ROS_INFO("Linear X: %f - Angular Z: %f", this->current_linear_x,
             this->current_angular_z);
  }

  if (cvui::button(frame, ((width / 3) + 10), (420 + 30), ((width / 3) - 20),
                   100, "Backward")) {
    ROS_INFO("Button Backward clicked...");

    geometry_msgs::Twist msg;

    msg.linear.x = this->current_linear_x - linear_x_step;
    msg.angular.z = this->current_angular_z;

    this->current_linear_x = msg.linear.x;
    this->current_angular_z = msg.angular.z;

    this->pub_.publish(msg);

    ROS_INFO("Linear X: %f - Angular Z: %f", this->current_linear_x,
             this->current_angular_z);
  }
}
