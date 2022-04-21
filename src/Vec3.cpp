#include "Vec3.hpp"

Vec3::Vec3() : e{0, 0, 0} {}
Vec3::Vec3(double x, double y, double z) : e{x, y, z} {}
double Vec3::lengthSq() const { return x*x + y*y + z*z; }
double Vec3::length() const { return sqrt(lengthSq()); }



// Unary negation
Vec3 operator-(const Vec3 &v) {
  return Vec3{-v.x, -v.y, -v.z};
}

// Addition
Vec3 operator+(const Vec3 &left, const Vec3 &right) {
  return Vec3{left.x+right.x, left.y+right.y, left.z+right.z};
}

// Addition assignment
Vec3 &operator+=(Vec3 &left, const Vec3 &right) {
  left.x += right.x;
  left.y += right.y;
  left.z += right.z;
  return left;
}

// Subtraction assignment
Vec3 &operator-=(Vec3 &left, const Vec3 &right) {
  return left += -right;
}

// Scalar multiplication assignment
Vec3 &operator*=(Vec3 &v, const double scalar) {
  v.x *= scalar;
  v.y *= scalar;
  v.z *= scalar;
  return v;
}

// Scalar division assignment
Vec3 &operator/=(Vec3 &v, const double scalar) {
  return v *= 1/scalar;
}

// Equality
bool operator==(const Vec3 &left, const Vec3 &right) {
  return left.x==right.x && left.y==right.y && left.z==right.z;
}

// Stream insertion
std::ostream &operator<<(std::ostream &out, const Vec3 &v) {
  return out << v.x << ' ' << v.y << ' ' << v.z;
}