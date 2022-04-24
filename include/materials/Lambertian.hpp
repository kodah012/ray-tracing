#pragma once

#include "../Vec3.hpp"
#include "Material.hpp"

class Lambertian : public Material {
 public:
  Vec3 &albedo = matAlbedo;

  Lambertian(const Vec3 &albedo) : matAlbedo{albedo} {}
  
  virtual bool scatter(
    const Ray &rayIn, const HitRecord &record, Vec3 &attenuation, Ray &rayOut
  ) const override {
    auto scatterDirection = record.faceNormal + Vec3::randomUnitVector();
    rayOut = Ray{record.hitPoint, scatterDirection};
    attenuation = albedo;
    return true;
  }
 
 private:
  Vec3 matAlbedo;
};