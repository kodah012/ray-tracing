#pragma once

#include <cmath>
#include <iostream>

class Vec3 {
 public:
  double &x = e[0];
  double &y = e[1];
  double &z = e[2];

  Vec3() : e{0, 0, 0} {}
  Vec3(double x, double y, double z) : e{x, y, z} {}

  Vec3 operator-() const { return Vec3(-x, -y, -z); }

  Vec3 operator+(const Vec3 &otherVector) {
    return Vec3{x+otherVector.x, y+otherVector.y, z+otherVector.z};
  }

  Vec3 &operator+=(const Vec3 &otherVector) {
    x += otherVector.x;
    y += otherVector.y;
    z += otherVector.z;
    return *this;
  }

  Vec3 &operator*=(const double scalar) {
    x *= scalar;
    y *= scalar;
    z *= scalar;
    return *this;
  }

  Vec3 &operator/=(const double scalar) {
    x /= scalar;
    y /= scalar;
    z /= scalar;
    return *this;
  }

  bool operator==(const Vec3 &otherVector) {
    return x==otherVector.x && y==otherVector.y && z==otherVector.z;
  }

  //friend std::ostream &operator<<(std::ostream &out, const Vec3 &v);

  double lengthSq() const { return x*x + y*y + z*z; }
  double length() const { return sqrt(lengthSq()); }

 private:
  double e[3];
};

inline std::ostream &operator<<(std::ostream &out, const Vec3 &v) {
  return out << v.x << ' ' << v.y << ' ' << v.z;
}
