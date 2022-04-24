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
#include "Camera.hpp"

#include <iostream>
#include <filesystem>

Vec3 colorFromRay(const Ray &r, const Hittable &world, int depth) {
  // If exceeded ray bounce limit, no more light is gathered
  if (depth <= 0) {
    Vec3 black{0, 0, 0};
    return black;
  }

  HitRecord record = world.raycast(r, 0.001, Math::infinity);
  if (record.hitAnything) {
    Vec3 target = record.hitPoint + record.faceNormal + Vec3::randomUnitVector();
    return 0.5 * colorFromRay(Ray{record.hitPoint, target - record.hitPoint}, world, depth-1);
  }

  Vec3 white{1, 1, 1};
  Vec3 blue{0.5, 0.7, 1};
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
  const int samplesPerPixel = 100;
  const int maxDepth = 50;
  unsigned char pixels[imageWidth * imageHeight * numChannels];

  // World
  HittableList world;
  world.add(std::make_shared<Sphere>(Vec3{0, 0, -1}, 0.5));
  world.add(std::make_shared<Sphere>(Vec3{0, -100.5, -1}, 100));

  // Camera
  Camera cam;
  
  // Render
  int i = 0;
  for (int row = imageHeight - 1; row >= 0; row--) {
    std::cout << "\rScanlines remaining: " << row << ' ' << std::flush;

    for (int col = 0; col < imageWidth; col++) {
      Vec3 pixelColor = Vec3::ZERO;

      for (int sample = 0; sample < samplesPerPixel; sample++) {
        auto u = (col + Math::randomDouble()) / (imageWidth - 1.0);
        auto v = (row + Math::randomDouble()) / (imageHeight - 1.0);
        Ray ray = cam.rayFromViewportPoint(u, v);
        pixelColor += colorFromRay(ray, world, maxDepth);
      }
      auto r = pixelColor.r;
      auto g = pixelColor.g;
      auto b = pixelColor.b;

      // Divide the color by the number of samples and gamma-correct for gamma=2.0
      auto scale = 1.0 / samplesPerPixel;
      r = sqrt(scale * r);
      g = sqrt(scale * g);
      b = sqrt(scale * b);

      // Write the translated [0, 255] value of each color component
      pixels[i++] = static_cast<unsigned char>(255.0 * Math::clamp(r, 0, 1));
      pixels[i++] = static_cast<unsigned char>(255.0 * Math::clamp(g, 0, 1));
      pixels[i++] = static_cast<unsigned char>(255.0 * Math::clamp(b, 0, 1));
    }
  }

  std::string outputDir = std::filesystem::current_path() / "image.png";
  stbi_write_png(outputDir.c_str(), imageWidth, imageHeight, numChannels, pixels, imageWidth * numChannels);

  std::cout << "\nDone.\n";
}

