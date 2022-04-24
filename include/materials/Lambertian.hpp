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

    // Catch degenerate scatter direction (occurs when random vector is exactly opposite normal)
    if (scatterDirection.approxEquals(Vec3::ZERO, 1e-8)) {
      scatterDirection = record.faceNormal;
    }

    rayOut = Ray{record.hitPoint, scatterDirection};
    attenuation = albedo;
    return true;
  }
 
 private:
  Vec3 matAlbedo;
};