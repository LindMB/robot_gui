#include "robot_gui/utils.h"
#include <iomanip>
#include <sstream>

std::string Utils::double_to_string_n_deci(double val, int nb_deci) {

  std::ostringstream oss;
  if (nb_deci < 0 || nb_deci > 19) {
    oss << std::fixed << std::setprecision(0) << val;
  } else {
    oss << std::fixed << std::setprecision(nb_deci) << val;
  }

  return oss.str();
}