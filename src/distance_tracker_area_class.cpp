#include "robot_gui/distance_tracker_area_class.h"
#include "ros/message_forward.h"
#include "std_srvs/Empty.h"
#include "std_srvs/Trigger.h"

CVUIROSDistanceTrackerArea::CVUIROSDistanceTrackerArea(ros::NodeHandle *nh) {

  this->distance = "0.00";

  this->get_distance_srv_client =
      nh->serviceClient<std_srvs::Trigger>("get_distance");

  this->reset_distance_srv_client =
      nh->serviceClient<std_srvs::Empty>("reset_distance");
}

void CVUIROSDistanceTrackerArea::draw(cv::Mat &frame, const int &width) {

  // Distance Tracker Area Title
  cvui::printf(frame, 10, 665, 0.4, 0xffffff, "Distance travelled");

  // cvui::button(frame, x, y, largeur, hauteur, "Texte")
  if (cvui::button(frame, 10, (665 + 20), ((width / 3) - 20), 30, "Call")) {
    ROS_INFO("Get Distance service called...");

    if (!this->get_distance_srv_client.exists()) {
      ROS_WARN("Service not available");

    } else {

      std_srvs::Trigger trigger_srv_msg;

      if (this->get_distance_srv_client.call(trigger_srv_msg)) {
        ROS_INFO("Service called successfully");

        this->distance = trigger_srv_msg.response.message;
        ROS_INFO("Distance travelled (m): %s", this->distance.c_str());

      } else {
        ROS_ERROR("Failed to call service");
      }
    }
  }

  if (cvui::button(frame, 10, (665 + 60), ((width / 3) - 20), 20, "Reset")) {
    ROS_INFO("Reset Distance service called...");

    if (!this->reset_distance_srv_client.exists()) {
      ROS_WARN("Service not available");

    } else {

      std_srvs::Empty empty_srv_msg;

      if (this->reset_distance_srv_client.call(empty_srv_msg)) {
        ROS_INFO("Service called successfully");

        this->distance = "0.00";
        ROS_INFO("Distance travelled reset to : %s", this->distance.c_str());

      } else {
        ROS_ERROR("Failed to call service");
      }
    }
  }

  // cvui::window(frame, x, y, largeur, hauteur, "Texte")
  cvui::window(frame, (width / 3 + 10), (665 + 20), ((width / 3) * 2 - 20), 60,
               "Distance in meters");

  // Show distance in meters inside the window.
  cvui::printf(frame, ((width / 3) * 2), (665 + 50), 0.8, 0xffffff,
               this->distance.c_str());
}