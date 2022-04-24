#include "Camera.hpp"

Camera::Camera() {
  auto aspectRatio = 16.0 / 9.0;
  auto viewportHeight = 2.0;
  auto viewportWidth = aspectRatio * viewportHeight;
  auto focalLength = 1.0;

  origin = Vec3::ZERO;
  viewportHorizontal = Vec3{viewportWidth, 0, 0};
  viewportVertical = Vec3{0, viewportHeight, 0};

  auto viewportCenter = origin - Vec3{0, 0, focalLength};
  viewportBottomLeft = viewportCenter - viewportHorizontal/2 - viewportVertical/2;
}

Ray Camera::rayFromViewportPoint(const double u, const double v) const {
  auto rayDirection = viewportBottomLeft + u*viewportHorizontal + v*viewportVertical;
  return Ray{origin, rayDirection};
}