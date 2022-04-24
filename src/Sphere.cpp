#include "Sphere.hpp"

Sphere::Sphere() = default;
Sphere::Sphere(Vec3 center, double radius) : cen{center}, rad{radius} {}

HitRecord Sphere::raycast(const Ray &r, const double tMin, const double tMax) const {
  HitRecord record;

  Vec3 centerToRayOrigin = r.origin - center;
  auto a = r.direction.lengthSq();
  auto bHalved = centerToRayOrigin.dot(r.direction);
  auto c = centerToRayOrigin.lengthSq() - radius*radius;

  // Check if root exists
  auto discriminant = bHalved*bHalved - a*c;
  if (discriminant < 0) {
    return record;
  }

  // Find the nearest root that lies in acceptable range
  auto sqrtDiscriminant = sqrt(discriminant);
  auto root = (-bHalved - sqrtDiscriminant) / a;
  if (root < tMin || root > tMax) {
    root = (-bHalved + sqrtDiscriminant) / a;
    if (root < tMin || root > tMax) {
      return record;
    }
  }

  const auto &rayProgress = root;
  const auto hitPoint = r.lerp(rayProgress);
  const Vec3 outwardNormal = (hitPoint - center) / radius;
  record = HitRecord{r, rayProgress, outwardNormal};
  
  return record;
}