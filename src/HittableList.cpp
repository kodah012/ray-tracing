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

bool HittableList::wasHit(
  const Ray &r, const double tMin, const double tMax, HitRecord &record
) const {
  HitRecord tempRecord;
  bool hitAnything = false;
  auto tClosest = tMax;

  for (const auto &object : objects) {
    if (object->wasHit(r, tMin, tClosest, tempRecord)) {
      hitAnything = true;
      tClosest = tempRecord.rayProgress;
      record = tempRecord;
    }
  }

  return hitAnything;
}