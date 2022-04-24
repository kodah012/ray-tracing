#include "Vec3.hpp"
#include "Utils.hpp"

// ---------- VEC3 CLASS ----------

const Vec3 Vec3::ZERO{0, 0, 0};

Vec3::Vec3() : e{0, 0, 0} {}
Vec3::Vec3(double x, double y, double z) : e{x, y, z} {}
Vec3::Vec3(const Vec3 &v) : e{v.x, v.y, v.z} {}


Vec3 Vec3::random() {
  return Vec3{Math::randomDouble(), Math::randomDouble(), Math::randomDouble()};
}
Vec3 Vec3::random(const double min, const double max) {
  return Vec3{
    Math::randomDouble(min, max),
    Math::randomDouble(min, max),
    Math::randomDouble(min, max)
  };
}
Vec3 Vec3::randomInsideUnitSphere() {
  while (true) {
    auto point = Vec3::random(-1, 1);
    if (point.lengthSq() < 1) {
      return point;
    }
  }
}
Vec3 Vec3::randomInsideUnitHemisphere(const Vec3 &normal) {
  Vec3 insideUnitSphere = randomInsideUnitSphere();
  if (insideUnitSphere.dot(normal) < 0) {
    // Outside hemisphere that normal vector is pointing toward, so reverse the random vector
    insideUnitSphere *= -1;
  }
  return insideUnitSphere;
}
Vec3 Vec3::randomUnitVector() {
  return randomInsideUnitSphere().normalized();
}


double Vec3::lengthSq() const {
  return x*x + y*y + z*z;
}
double Vec3::length() const {
  return sqrt(lengthSq());
}
double Vec3::dot(const Vec3 &v) const {
  return x*v.x + y*v.y + z*v.z;
}
Vec3 Vec3::cross(const Vec3 &v) const {
  return Vec3{y*v.z - z*v.y, z*v.x - x*v.z, x*v.y - y*v.x};
}

Vec3 Vec3::normalized() const {
  Vec3 result = *this;
  double lengthSq = result.lengthSq();

  if (lengthSq != 0 && lengthSq != 1) {
    result /= sqrt(lengthSq);
  }
  return result;
}

Vec3 Vec3::lerp(const Vec3 &target, const double t) const {
  const Vec3 &start = *this;
  return start + (target - start) * t;
}

Vec3 Vec3::reflected(const Vec3 &normal) const {
  auto &v = *this;
  return v - 2*v.dot(normal)*normal;
}

bool Vec3::approxEquals(const Vec3 &v, double error) const {
  bool xApproxEqual = std::abs(x - v.x) <= error;
  bool yApproxEqual = std::abs(y - v.y) <= error;
  bool zApproxEqual = std::abs(z - v.z) <= error;
  return xApproxEqual && yApproxEqual && zApproxEqual;
}

// ---------- OPERATOR OVERLOADS ----------

// Copy assignment
Vec3 &Vec3::operator=(const Vec3 &v) {
  e[0] = v.x;
  e[1] = v.y;
  e[2] = v.z;
  return *this;
}

// Unary negation
Vec3 operator-(const Vec3 &v) {
  return Vec3{-v.x, -v.y, -v.z};
}

// Addition
Vec3 operator+(const Vec3 &left, const Vec3 &right) {
  return Vec3{left.x+right.x, left.y+right.y, left.z+right.z};
}

// Subtraction
Vec3 operator-(const Vec3 &left, const Vec3 &right) {
  return left + -right;
}

// Scalar multiplication
Vec3 operator*(const Vec3 &v, const double &scalar) {
  return Vec3{v.x*scalar, v.y*scalar, v.z*scalar};
}
Vec3 operator*(const double &scalar, const Vec3 &v) {
  return v * scalar;
}

// Scalar division
Vec3 operator/(const Vec3 &v, const double &scalar) {
  return v * (1/scalar);
}

// Addition assignment
Vec3 &operator+=(Vec3 &left, const Vec3 &right) {
  left.e[0] += right.x;
  left.e[1] += right.y;
  left.e[2] += right.z;
  return left;
}

// Subtraction assignment
Vec3 &operator-=(Vec3 &left, const Vec3 &right) {
  return left += -right;
}

// Scalar multiplication assignment
Vec3 &operator*=(Vec3 &v, const double &scalar) {
  v.e[0] *= scalar;
  v.e[1] *= scalar;
  v.e[2] *= scalar;
  return v;
}

// Scalar division assignment
Vec3 &operator/=(Vec3 &v, const double &scalar) {
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
