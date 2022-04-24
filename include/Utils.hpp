#pragma once

#include <cmath>
#include <limits>
#include <memory>

namespace Math {

  const double infinity = std::numeric_limits<double>::infinity();
  const double pi = M_PI;

  inline double degreesToRadians(double degrees) {
    return degrees * pi / 180.0;
  }

}