#include "Sphere.hpp"
#include <memory>

Sphere::Sphere() = default;
Sphere::Sphere(
  const Vec3 &center, const double radius, const std::shared_ptr<Material> material
) : cen{center}, rad{radius}, mat{material} {}

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
  record = HitRecord{r, rayProgress, outwardNormal, material};
  
  return record;
}