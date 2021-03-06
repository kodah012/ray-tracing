#include "Ray.hpp"

#include <memory>

Ray::Ray() = default;
Ray::Ray(const Vec3 &origin, const Vec3 &direction)
  : orig{origin}, dir{direction} {}

Vec3 Ray::lerp(double t) const {
  return origin + t*direction;
}

Ray &Ray::operator=(const Ray &r) {
  orig = r.origin;
  dir = r.direction;
  return *this;
}