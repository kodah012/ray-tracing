#pragma once

#include <cmath>
#include <iostream>

class vec3 {
 public:
  double &x = e[0];
  double &y = e[1];
  double &z = e[2];

  vec3() : e{0, 0, 0} {}
  vec3(double x, double y, double z) : e{x, y, z} {}

  vec3 operator-() const { return vec3(-x, -y, -z); }

  vec3 &operator+=(const vec3 &otherVector) {
    x += otherVector.x;
    y += otherVector.y;
    z += otherVector.z;
    return *this;
  }

  vec3 &operator*=(const double scalar) {
    x *= scalar;
    y *= scalar;
    z *= scalar;
    return *this;
  }

  vec3 &operator/=(const double scalar) {
    x /= scalar;
    y /= scalar;
    z /= scalar;
    return *this;
  }

  double lengthSq() const { return x*x + y*y + z*z; }
  double length() const { return sqrt(lengthSq()); }

 private:
  double e[3];
};