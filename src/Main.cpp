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
#include "materials/Material.hpp"
#include "materials/Lambertian.hpp"
#include "materials/Metal.hpp"
#include "materials/Dielectric.hpp"

#include <iostream>
#include <filesystem>

Vec3 colorFromRay(const Ray &r, const Hittable &world, int depth) {
  Vec3 black = Vec3::ZERO;

  // If exceeded ray bounce limit, no more light is gathered
  if (depth <= 0) {
    return black;
  }

  HitRecord record = world.raycast(r, 0.001, Math::infinity);
  if (record.hitAnything) {
    Ray scattered;
    Vec3 attenuation;
    if (record.material->scatter(r, record, attenuation, scattered)) {
      Vec3 colorResult = colorFromRay(scattered, world, depth - 1);
      return Vec3{
        attenuation.x * colorResult.x,
        attenuation.y * colorResult.y,
        attenuation.z * colorResult.z
      };
    }
    return black;
  }

  Vec3 white{1, 1, 1};
  Vec3 blue{0.5, 0.7, 1};
  auto unitDirection = r.direction.normalized();
  auto t = 0.5 * (unitDirection.y + 1);
  return (1-t)*white + t*blue;
}

HittableList createWorld() {
  HittableList world;

  auto groundMat = std::make_shared<Lambertian>(Vec3{0.8, 0.8, 0});
  auto centerMat = std::make_shared<Lambertian>(Vec3{0.1, 0.2, 0.5});
  auto leftMat = std::make_shared<Dielectric>(1.5);
  auto rightMat = std::make_shared<Metal>(Vec3{0.8, 0.6, 0.2}, 0);

  auto groundSphere = std::make_shared<Sphere>(Vec3{0, -100.5, -1}, 100, groundMat);
  auto centerSphere = std::make_shared<Sphere>(Vec3{0, 0, -1}, 0.5, centerMat);
  auto leftSphere = std::make_shared<Sphere>(Vec3{-1, 0, -1}, 0.5, leftMat);
  auto rightSphere = std::make_shared<Sphere>(Vec3{1, 0, -1}, 0.5, rightMat);

  world.add(groundSphere);
  world.add(centerSphere);
  world.add(leftSphere);
  world.add(rightSphere);

  return world;
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
  auto world = createWorld();

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

