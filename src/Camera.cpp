#include "Camera.hpp"
#include "Utils.hpp"

Camera::Camera(
  const Vec3 &lookFrom, const Vec3 &lookAt, const Vec3 &viewUp,
  double verticalFov, double aspectRatio
) {
  double theta = Math::degreesToRadians(verticalFov);
  double h = tan(theta/2);
  double viewportHeight = 2 * h;
  double viewportWidth = aspectRatio * viewportHeight;

  Vec3 camBackward = (lookFrom - lookAt).normalized();
  Vec3 camRight = viewUp.cross(camBackward).normalized();
  Vec3 camUp = camBackward.cross(camRight);

  origin = lookFrom;
  viewportHorizontal = viewportWidth * camRight;
  viewportVertical = viewportHeight * camUp;
  viewportBottomLeft = origin - viewportHorizontal/2 - viewportVertical/2 - camBackward;
}

Ray Camera::rayFromViewportPoint(const double u, const double v) const {
  Vec3 rayDirection = viewportBottomLeft + u*viewportHorizontal + v*viewportVertical - origin;
  return Ray{origin, rayDirection};
}
