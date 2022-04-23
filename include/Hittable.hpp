#pragma once

#include "Ray.hpp"

class HitRecord {
 public:
  const Vec3 &hitPoint = point;
  const Vec3 &faceNormal = normal;
  const double &rayProgress = t;
  const bool &frontFaceWasHit = frontFace;

  HitRecord(const Vec3 &hitPoint, const double rayProgress, const Ray &r, const Vec3 &outwardNormal) {
    point = hitPoint;
    t = rayProgress;
    setFaceNormal(r, outwardNormal);
  }

  HitRecord &operator=(const HitRecord &record) {
    point = record.hitPoint;
    t = record.rayProgress;
    normal = record.faceNormal;
    frontFace = record.frontFaceWasHit;
    return *this;
  }

 private:
  Vec3 point;
  Vec3 normal;
  double t;
  bool frontFace;

  void setFaceNormal(const Ray &r, const Vec3 &outwardNormal) {
    frontFace = r.direction.dot(outwardNormal) < 0;
    normal = frontFace ? outwardNormal : -outwardNormal;
  }
};

class Hittable {
 public:
  virtual bool wasHit(const Ray &r, const double tMin, const double tMax, HitRecord &record) const = 0;
};