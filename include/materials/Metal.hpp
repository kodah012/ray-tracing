#pragma once

#include "Material.hpp"

class Metal : public Material {
 public:
  Vec3 &albedo = matAlbedo;

  Metal(const Vec3 &albedo) : matAlbedo{albedo} {}

  virtual bool scatter(
    const Ray &rayIn, const HitRecord &record, Vec3 &attenuation, Ray &rayOut
  ) const override {
    Vec3 reflected = rayIn.direction.normalized().reflected(record.faceNormal);
    rayOut = Ray(record.hitPoint, reflected);
    attenuation = albedo;
    return rayOut.direction.dot(record.faceNormal) > 0;
  }

 private:
  Vec3 matAlbedo;
};