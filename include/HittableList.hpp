#pragma once

#include "Hittable.hpp"

#include <memory>
#include <vector>

class HittableList : public Hittable {
 public:
  HittableList();
  HittableList(const std::shared_ptr<Hittable> object);

  void clear();
  void add(const std::shared_ptr<Hittable> object);

  virtual HitRecord raycast(const Ray &r, const double tMin, const double tMax) const override;
 
 private:
  std::vector<std::shared_ptr<Hittable>> objects;
};