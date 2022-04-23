#pragma once

#include "Hittable.hpp"

#include <memory>
#include <vector>

class HittableList : public Hittable {
 public:
  HittableList() = default;
  HittableList(const std::shared_ptr<Hittable> &object) {
    add(object);
  }

  void clear();
  void add(const std::shared_ptr<Hittable> &object);

  virtual bool wasHit(
    const Ray &r, const double tMin, const double tMax, HitRecord &record
  ) const override;
 
 private:
  std::vector<std::shared_ptr<Hittable>> objects;
};