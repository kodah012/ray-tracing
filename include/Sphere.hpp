#pragma once

#include "Hittable.hpp"
#include "Vec3.hpp"

class Sphere : public Hittable {
 public:
  const Vec3 &center = cen;
  const double &radius = rad;

  Sphere();
  Sphere(Vec3 center, double radius);

  virtual bool wasHit(
    const Ray &r,
    const double tMin, const double tMax,
    HitRecord &record
  ) const override;

 private:
  Vec3 cen;
  double rad;
};