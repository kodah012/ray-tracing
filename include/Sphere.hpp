#pragma once

#include "Vec3.hpp"
#include "Hittable.hpp"
#include <memory>

class Sphere : public Hittable {
 public:
  const Vec3 &center = cen;
  const double &radius = rad;
  const std::shared_ptr<Material> &material = mat;

  Sphere();
  Sphere(Vec3 center, double radius, std::shared_ptr<Material> material);

  virtual HitRecord raycast(const Ray &r, const double tMin, const double tMax) const override;

 private:
  Vec3 cen;
  double rad;
  std::shared_ptr<Material> mat;
};