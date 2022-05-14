#include "Camera.hpp"
#include "Utils.hpp"

Camera::Camera(double verticalFov, double aspectRatio) {
  double theta = Math::degreesToRadians(verticalFov);
  double h = tan(theta/2);
  double viewportHeight = 2 * h;
  double viewportWidth = aspectRatio * viewportHeight;
  double focalLength = 1.0;

  origin = Vec3::ZERO;
  viewportHorizontal = Vec3{viewportWidth, 0, 0};
  viewportVertical = Vec3{0, viewportHeight, 0};

  Vec3 viewportCenter = origin - Vec3{0, 0, focalLength};
  viewportBottomLeft = viewportCenter - viewportHorizontal/2 - viewportVertical/2;
}

Ray Camera::rayFromViewportPoint(const double u, const double v) const {
  auto rayDirection = viewportBottomLeft + u*viewportHorizontal + v*viewportVertical;
  return Ray{origin, rayDirection};
}