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
    if (!canRefract || reflectance(cosTheta, refractIndexFrom, refractIndexTo) > Math::randomDouble()) {
      rayOutDir = rayInDir.reflected(record.faceNormal);
    }
    else {
      rayOutDir = rayInDir.refracted(record.faceNormal, refractIndexFrom, refractIndexTo);
    }

    attenuation = Vec3{1, 1, 1}; // 1 because glass surface does not absorb anything
    rayOut = Ray{record.hitPoint, rayOutDir};
    return true;
  }

 private:
  double refractIndex;

  static double reflectance(double cosTheta, double refractIndexFrom, double refractIndexTo) {
    // Use Schlick's approximation for reflectance
    double refractIndexRatio = refractIndexFrom / refractIndexTo;
    auto r0 = (1-refractIndexRatio) / (1+refractIndexRatio);
    r0 *= r0;
    return r0 + (1-r0)*pow(1-cosTheta, 5);
  }
};