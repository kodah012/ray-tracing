//#define STB_IMAGE_IMPLEMENTATION
//#include "stb_image.h"

#include <memory>
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

#include "Vec3.hpp"
#include "Ray.hpp"
#include "Hittable.hpp"
#include "HittableList.hpp"
#include "Utils.hpp"
#include "Sphere.hpp"

#include <iostream>
#include <filesystem>

Vec3 colorFromRay(const Ray &r, const Hittable &world) {
  Vec3 white{1, 1, 1};
  Vec3 blue{0.5, 0.7, 1};

  HitRecord record = world.raycast(r, 0, Math::infinity);
  if (record.hitAnything) {
    return 0.5 * (record.faceNormal + Vec3{1, 1, 1});
  }

  auto unitDirection = r.direction.normalized();
  auto t = 0.5 * (unitDirection.y + 1);
  return (1-t)*white + t*blue;
}


int main(int argc, char *argv[]) {
  // Image
  const auto aspectRatio = 16.0 / 9.0;
  const int imageWidth = 400;
  const int imageHeight = static_cast<int>(imageWidth / aspectRatio);
  const int numChannels = 3;
  unsigned char pixels[imageWidth * imageHeight * numChannels];

  // World
  HittableList world;
  world.add(std::make_shared<Sphere>(Vec3{0, 0, -1}, 0.5));
  world.add(std::make_shared<Sphere>(Vec3{0, -100.5, -1}, 100));

  // Camera
  auto viewportHeight = 2.0;
  auto viewportWidth = viewportHeight * aspectRatio;
  auto viewportVertical = Vec3{0, viewportHeight, 0};
  auto viewportHorizontal = Vec3{viewportWidth, 0, 0};
  auto focalLength = 1.0;
  auto camOrigin = Vec3::ZERO;
  auto viewportLowerLeftCorner =
    camOrigin -
    viewportHorizontal/2 - viewportVertical/2 -
    Vec3{0, 0, focalLength};
  
  // Render
  int i = 0;
  for (int row = imageHeight - 1; row >= 0; row--) {
    std::cout << "\rScanlines remaining: " << row << ' ' << std::flush;
    for (int col = 0; col < imageWidth; col++) {
      auto u = col / double(imageWidth - 1);
      auto v = row / double(imageHeight - 1);

      Ray r{
        camOrigin,
        viewportLowerLeftCorner + u*viewportHorizontal + v*viewportVertical
      };
      Vec3 color = colorFromRay(r, world);

      pixels[i++] = static_cast<unsigned char>(255.0 * color.r);
      pixels[i++] = static_cast<unsigned char>(255.0 * color.g);
      pixels[i++] = static_cast<unsigned char>(255.0 * color.b);
    }
  }

  std::string outputDir = std::filesystem::current_path() / "image.png";
  stbi_write_png(outputDir.c_str(), imageWidth, imageHeight, numChannels, pixels, imageWidth * numChannels);

  std::cout << "\nDone.\n";
}

