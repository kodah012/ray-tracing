#pragma once

#include "Ray.hpp"

struct HitRecord {
  Vec3 point;
  Vec3 normal;
  double t;
};

class Hittable {
 public:
  virtual bool wasHit(const Ray &r, double tMin, double tMax, HitRecord record) const = 0;
};