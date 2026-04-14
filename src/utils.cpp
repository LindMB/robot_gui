#include "robot_gui/utils.h"
#include <iomanip>
#include <sstream>

std::string Utils::double_to_string_2_deci(double val) {

  std::ostringstream oss;
  oss << std::fixed << std::setprecision(2) << val;

  return oss.str();
}