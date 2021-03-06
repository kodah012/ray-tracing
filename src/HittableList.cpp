#include "HittableList.hpp"

HittableList::HittableList() = default;
HittableList::HittableList(const std::shared_ptr<Hittable> object) {
  add(object);
}

void HittableList::clear() {
  objects.clear();
}
void HittableList::add(const std::shared_ptr<Hittable> object) {
  objects.push_back(object);
}

HitRecord HittableList::raycast(const Ray &r, const double tMin, const double tMax) const {
  HitRecord record;
  auto tClosest = tMax;

  for (const auto &object : objects) {
    HitRecord tempRecord = object->raycast(r, tMin, tClosest);
    if (tempRecord.hitAnything) {
      tClosest = tempRecord.rayProgress;
      record = tempRecord;
    }
  }

  return record;
}