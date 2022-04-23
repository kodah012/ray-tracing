#pragma once

#include "Ray.hpp"
#include "HitRecord.hpp"

class Hittable {
 public:
  virtual bool wasHit(const Ray &r, const double tMin, const double tMax, HitRecord &record) const = 0;
};