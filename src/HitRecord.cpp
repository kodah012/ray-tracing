#include "HitRecord.hpp"
#include <memory>

HitRecord::HitRecord() : hit{false} {};
HitRecord::HitRecord(
  const Ray &r, const double rayProgress, const Vec3 &outwardNormal, std::shared_ptr<Material> material
) : t{rayProgress}, point{r.lerp(rayProgress)}, mat{material}, hit{true} {
  frontFace = r.direction.dot(outwardNormal) < 0;
  normal = frontFace ? outwardNormal : -outwardNormal;
}

HitRecord &HitRecord::operator=(const HitRecord &record) {
  point = record.hitPoint;
  t = record.rayProgress;
  normal = record.faceNormal;
  frontFace = record.hitFrontFace;
  mat = record.material;
  hit = record.hitAnything;
  return *this;
}
