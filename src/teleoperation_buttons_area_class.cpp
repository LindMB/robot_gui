#include "robot_gui/teleoperation_buttons_area_class.h"
#include <geometry_msgs/Twist.h>
#include <ros/ros.h>

CVUIROSTeleopButtonsArea::CVUIROSTeleopButtonsArea(ros::NodeHandle *nh) {

  this->pub_ = nh->advertise<geometry_msgs::Twist>("/cooper_1/cmd_vel", 10);
}

void CVUIROSTeleopButtonsArea::draw(cv::Mat &frame, const int &width) {

  // cvui::button(frame, x, y, largeur, hauteur, "Texte")
  if (cvui::button(frame, 10, (320 + 10), ((width / 3) - 20), 100, "Left")) {
    std::cout << "Left clique" << std::endl;
  }

  if (cvui::button(frame, ((width / 3) + 10), 210, ((width / 3) - 20), 100,
                   "Forward")) {
    std::cout << "Forward clique" << std::endl;
  }

  if (cvui::button(frame, ((width / 3) + 10), (320 + 10), ((width / 3) - 20),
                   100, "Stop")) {
    std::cout << "Stop clique" << std::endl;
  }

  if (cvui::button(frame, (((width / 3) * 2) + 10), (320 + 10),
                   ((width / 3) - 20), 100, "Right")) {
    std::cout << "Right clique" << std::endl;
  }

  if (cvui::button(frame, ((width / 3) + 10), (420 + 30), ((width / 3) - 20),
                   100, "Backward")) {
    std::cout << "Backward clique" << std::endl;
  }
}
