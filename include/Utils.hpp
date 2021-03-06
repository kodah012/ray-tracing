#pragma once

#include <cmath>
#include <limits>
#include <memory>
#include <random>

namespace Math {

  const double infinity = std::numeric_limits<double>::infinity();
  const double pi = M_PI;

  inline double degreesToRadians(const double degrees) {
    return degrees * pi / 180.0;
  }

  // Returns a random real number in [0, 1)
  inline double randomDouble() {
    static std::uniform_real_distribution<double> distribution(0.0, 1.0);
    static std::mt19937 generator;
    return distribution(generator);
  }

  // Returns a random real number in [min, max)
  inline double randomDouble(const double min, const double max) {
    return min + (max - min) * randomDouble();
  }

  inline double clamp(const double x, const double min, const double max) {
    return std::clamp(x, min, max);
  }

}