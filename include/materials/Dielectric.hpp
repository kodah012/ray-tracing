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

    Vec3 unitDirection = rayIn.direction.normalized();
    Vec3 refracted = unitDirection.refracted(record.faceNormal, refractIndexFrom, refractIndexTo);

    attenuation = Vec3{1, 1, 1};
    rayOut = Ray{record.hitPoint, refracted};
    return true;
  }

 private:
  double refractIndex;
};