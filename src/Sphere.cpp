#include "Sphere.hpp"

Sphere::Sphere() = default;
Sphere::Sphere(Vec3 center, double radius) : cen{center}, rad{radius} {}

bool Sphere::wasHit(const Ray &r, const double tMin, const double tMax, HitRecord &record) const {
  Vec3 centerToRayOrigin = r.origin - center;
  auto a = r.direction.lengthSq();
  auto bHalved = centerToRayOrigin.dot(r.direction);
  auto c = centerToRayOrigin.lengthSq() - radius*radius;

  // Check if root exists
  auto discriminant = bHalved*bHalved - a*c;
  if (discriminant < 0) {
    return false;
  }

  // Find the nearest root that lies in acceptable range
  auto sqrtDiscriminant = sqrt(discriminant);
  auto root = (-bHalved - sqrtDiscriminant) / a;
  if (root < tMin || root > tMax) {
    root = (-bHalved + sqrtDiscriminant) / a;
    if (root < tMin || root > tMax) {
      return false;
    }
  }

  const auto &rayProgress = root;
  const Vec3 outwardNormal = (record.hitPoint - center) / radius;
  record = HitRecord{r.lerp(rayProgress), rayProgress, r, outwardNormal};
  
  return true;
}