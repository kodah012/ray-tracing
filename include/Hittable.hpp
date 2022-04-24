#pragma once

#include "HitRecord.hpp"

class Hittable {
 public:
  virtual HitRecord raycast(const Ray &r, const double tMin, const double tMax) const = 0;
};
