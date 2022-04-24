#pragma once

#include <cmath>
#include <iostream>

class Vec3 {
 public:
  const static Vec3 ZERO;

  const double &x = e[0];
  const double &y = e[1];
  const double &z = e[2];

  const double &r = x;
  const double &g = y;
  const double &b = z;

  const double &u = x;
  const double &v = y;
  const double &w = z;

  Vec3();
  Vec3(double x, double y, double z);
  Vec3(const Vec3 &v);

  static Vec3 random();
  static Vec3 random(const double min, const double max);
  static Vec3 randomInsideUnitSphere();
  static Vec3 randomInsideUnitHemisphere(const Vec3 &normal);
  static Vec3 randomUnitVector();

  double lengthSq() const;
  double length() const;
  double dot(const Vec3 &v) const;
  Vec3 cross(const Vec3 &v) const;
  Vec3 normalized() const;
  Vec3 lerp(const Vec3 &target, const double t) const;
  Vec3 reflected(const Vec3 &normal) const;
  bool approxEquals(const Vec3 &v, double error = 0.0001) const;

  Vec3 &operator=(const Vec3 &v);

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
