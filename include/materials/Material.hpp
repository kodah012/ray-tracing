#pragma once

#include "../Utils.hpp"
#include "../HitRecord.hpp"

class Material {
 public:
  virtual bool scatter(
    const Ray &rayIn, const HitRecord &record, Vec3 &attenuation, Ray &rayOut
  ) const = 0;
};