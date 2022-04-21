#pragma once

#include <cmath>
#include <iostream>

class Vec3 {
 public:
  const double &x = e[0];
  const double &y = e[1];
  const double &z = e[2];

  Vec3();
  Vec3(double x, double y, double z);

  double lengthSq() const;
  double length() const;
  double dot(const Vec3 &v) const;
  Vec3 cross(const Vec3 &v) const;
  Vec3 normalized() const;
  bool approxEquals(const Vec3 &v, double error = 0.001) const;

 private:
  double e[3];

  friend Vec3 &operator+=(Vec3 &left, const Vec3 &right);
  friend Vec3 &operator*=(Vec3 &v, const double &scalar);
};

Vec3 operator-(const Vec3 &v);
Vec3 operator+(const Vec3 &left, const Vec3 &right);
Vec3 operator-(const Vec3 &left, const Vec3 &right);
Vec3 operator*(const Vec3 &v, const double &scalar);
Vec3 operator*(const double &scalar, const Vec3 &v);
Vec3 operator/(const Vec3 &v, const double &scalar);
Vec3 &operator+=(Vec3 &left, const Vec3 &right);
Vec3 &operator-=(Vec3 &left, const Vec3 &right);
Vec3 &operator*=(Vec3 &v, const double &scalar);
Vec3 &operator/=(Vec3 &v, const double &scalar);
bool operator==(const Vec3 &left, const Vec3 &right);
std::ostream &operator<<(std::ostream &out, const Vec3 &v);
