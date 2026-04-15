#include "robot_gui/main_window_class.h"

CVUIROSMainWindow::CVUIROSMainWindow(ros::NodeHandle *nh)
    : general_info_area(nh), teleop_buttons_area(nh), robot_position_area(nh),
      distance_tracker_area(nh) {

  // Init a OpenCV window and tell cvui to use it.
  cv::namedWindow(this->WINDOW_NAME);
  cvui::init(this->WINDOW_NAME);
}

void CVUIROSMainWindow::run() {

  // Initialize main window size (Height: 800 pixels, Width: 500 pixels)
  cv::Mat frame = cv::Mat(this->height, this->width, CV_8UC3);

  // Fill the frame with a grey color
  frame = cv::Scalar(49, 52, 49);

  while (ros::ok()) {

    // Draw the general info area
    this->general_info_area.draw(frame, this->width);
    // Draw the teleoperation buttons area
    this->teleop_buttons_area.draw(frame, this->width);
    // Draw the robot position area
    this->robot_position_area.draw(frame, this->width);
    // Draw the distance tracker area
    this->distance_tracker_area.draw(frame, this->width);

    // Update cvui internal stuff
    cvui::update();

    // Show everything on the screen
    cv::imshow(this->WINDOW_NAME, frame);

    // Check if ESC key was pressed
    if (cv::waitKey(20) == 27) {
      break;
    }
    // Spin as a single-threaded node
    ros::spinOnce();
  }
}