#pragma once

#include "Vec3.hpp"
#include "Hittable.hpp"

class Sphere : public Hittable {
 public:
  const Vec3 &center = cen;
  const double &radius = rad;

  Sphere();
  Sphere(Vec3 center, double radius);

  virtual HitRecord raycast(const Ray &r, const double tMin, const double tMax) const override;

 private:
  Vec3 cen;
  double rad;
};