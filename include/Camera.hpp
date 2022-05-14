#pragma once

#include "Utils.hpp"
#include "Ray.hpp"

class Camera {
 public:
  Camera(double verticalFov, double aspectRatio);
  
  Ray rayFromViewportPoint(const double u, const double v) const;
 
 private:
  Vec3 origin;
  Vec3 viewportBottomLeft;
  Vec3 viewportHorizontal;
  Vec3 viewportVertical;
};