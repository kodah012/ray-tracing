#pragma once

#include "Vec3.hpp"
#include "Ray.hpp"

class HitRecord {
 public:
  const Vec3 &hitPoint = point;
  const Vec3 &faceNormal = normal;
  const double &rayProgress = t;
  const bool &hitFrontFace = frontFace;

  HitRecord();
  HitRecord(
    const Vec3 &hitPoint,
    const double rayProgress,
    const Ray &r,
    const Vec3 &outwardNormal
  );

  HitRecord &operator=(const HitRecord &record);

 private:
  Vec3 point;
  Vec3 normal;
  double t;
  bool frontFace;

  void setFaceNormal(const Ray &r, const Vec3 &outwardNormal);
};