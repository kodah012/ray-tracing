//#define STB_IMAGE_IMPLEMENTATION
//#include "stb_image.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

#include <iostream>
#include <filesystem>

#include "Vec3.hpp"
#include "Ray.hpp"

Vec3 rayColor(const Ray &r) {
  const Vec3 white{1, 1, 1};
  const Vec3 blue{0.5, 0.7, 1};

  Vec3 unitDirection = r.direction.normalized();
  auto t = 0.5 * (unitDirection.y + 1.0);

  return white.lerp(blue, t);
}

int main(int argc, char *argv[]) {
  // Image
  const auto aspectRatio = 16.0 / 9.0;
  const int imageWidth = 400;
  const int imageHeight = static_cast<int>(imageWidth / aspectRatio);
  const int numChannels = 3;
  unsigned char pixels[imageWidth * imageHeight * numChannels];

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
  
  int i = 0;
  for (int row = imageHeight - 1; row >= 0; row--) {
    std::cout << "\rScanlines remaining: " << row << ' ' << std::flush;
    for (int col = 0; col < imageWidth; col++) {
      auto u = col / double(imageWidth - 1);
      auto v = row / double(imageHeight - 1);

      Ray r{
        camOrigin,
        viewportLowerLeftCorner + u*viewportHorizontal + v*viewportVertical - camOrigin
      };
      Vec3 color = rayColor(r);

      pixels[i++] = static_cast<unsigned char>(255.0 * color.r);
      pixels[i++] = static_cast<unsigned char>(255.0 * color.g);
      pixels[i++] = static_cast<unsigned char>(255.0 * color.b);
    }
  }

  std::string outputDir = std::filesystem::current_path() / "image.png";
  stbi_write_png(outputDir.c_str(), imageWidth, imageHeight, numChannels, pixels, imageWidth * numChannels);

  std::cout << "\nDone.\n";
}

