#pragma once

#include "Vec3.hpp"

class Ray {
 public:
  const Vec3 &origin = orig;
  const Vec3 &direction = dir;

  Ray();
  Ray(const Vec3 &origin, const Vec3 &direction);

  Vec3 lerp(double t) const;
 
  Ray &operator=(const Ray &r);

 private:
  Vec3 orig;
  Vec3 dir;
};