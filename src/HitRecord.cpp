#include "HitRecord.hpp"

HitRecord::HitRecord() = default;
HitRecord::HitRecord(
  const Vec3 &hitPoint,
  const double rayProgress,
  const Ray &r,
  const Vec3 &outwardNormal
) {
  point = hitPoint;
  t = rayProgress;
  setFaceNormal(r, outwardNormal);
}

HitRecord &HitRecord::operator=(const HitRecord &record) {
  point = record.hitPoint;
  t = record.rayProgress;
  normal = record.faceNormal;
  frontFace = record.hitFrontFace;
  return *this;
}

void HitRecord::setFaceNormal(const Ray &r, const Vec3 &outwardNormal) {
  frontFace = r.direction.dot(outwardNormal) < 0;
  normal = frontFace ? outwardNormal : -outwardNormal;
}