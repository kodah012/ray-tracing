#include "Sphere.hpp"

Sphere::Sphere() = default;
Sphere::Sphere(Vec3 center, double radius) : cen{center}, rad{radius} {}

bool Sphere::wasHit(const Ray &r, double tMin, double tMax, HitRecord record) const {
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

  record.t = root;
  record.point = r.lerp(record.t);
  record.normal = (record.point - center) / radius;
  
  return true;
}