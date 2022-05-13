#pragma once

#include "Material.hpp"

class Dielectric : public Material {
 public:
  Dielectric(double refractiveIndex) : refractIndex{refractiveIndex} {}

  virtual bool scatter(
    const Ray &rayIn, const HitRecord &record, Vec3 &attenuation, Ray &rayOut
  ) const override {
    double refractIndexFrom;
    double refractIndexTo;
    if (record.hitFrontFace) {
      refractIndexFrom = 1;
      refractIndexTo = refractIndex;
    }
    else {
      refractIndexFrom = refractIndex;
      refractIndexTo = 1;
    }

    Vec3 rayInDir = rayIn.direction.normalized();
    double cosTheta = fmin((-rayInDir).dot(record.faceNormal), 1);
    double sinTheta = sqrt(1.0 - cosTheta*cosTheta);
    bool canRefract = (refractIndexFrom/refractIndexTo) * sinTheta <= 1;

    Vec3 rayOutDir;
    if (canRefract) {
      rayOutDir = rayInDir.refracted(record.faceNormal, refractIndexFrom, refractIndexTo);
    }
    else {
      rayOutDir = rayInDir.reflected(record.faceNormal);
    }

    attenuation = Vec3{1, 1, 1}; // 1 because glass surface does not absorb anything
    rayOut = Ray{record.hitPoint, rayOutDir};
    return true;
  }

 private:
  double refractIndex;
};