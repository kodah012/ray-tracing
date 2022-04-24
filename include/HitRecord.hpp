#pragma once

#include "Vec3.hpp"
#include "Ray.hpp"
#include <memory>

class Material;

class HitRecord {
 public:
  const Vec3 &hitPoint = point;
  const Vec3 &faceNormal = normal;
  const double &rayProgress = t;
  const bool &hitFrontFace = frontFace;
  const bool &hitAnything = hit;
  const std::shared_ptr<Material> material;

  HitRecord();
  HitRecord(
    const Ray &r, const double rayProgress, const Vec3 &outwardNormal, std::shared_ptr<Material> material
  );

  HitRecord &operator=(const HitRecord &record);

 private:
  Vec3 point;
  Vec3 normal;
  double t;
  bool frontFace;
  bool hit = false;
  std::shared_ptr<Material> mat;
};