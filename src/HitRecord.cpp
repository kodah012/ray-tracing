#include "HitRecord.hpp"

HitRecord::HitRecord() = default;
HitRecord::HitRecord(const Ray &r, const double rayProgress, const Vec3 &outwardNormal) {
  t = rayProgress;
  point = r.lerp(t);
  frontFace = r.direction.dot(outwardNormal) < 0;
  normal = frontFace ? outwardNormal : -outwardNormal;
}

HitRecord &HitRecord::operator=(const HitRecord &record) {
  point = record.hitPoint;
  t = record.rayProgress;
  normal = record.faceNormal;
  frontFace = record.hitFrontFace;
  return *this;
}
