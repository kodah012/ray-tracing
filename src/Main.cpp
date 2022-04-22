//#define STB_IMAGE_IMPLEMENTATION
//#include "stb_image.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

#include <iostream>
#include <filesystem>

#include "Vec3.hpp"
#include "Ray.hpp"

int main(int argc, char *argv[]) {
  const int imageWidth = 256;
  const int imageHeight = 256;
  const int numChannels = 3;
  unsigned char pixels[imageWidth * imageHeight * numChannels];
  
  int i = 0;
  for (int row = imageHeight - 1; row >= 0; row--) {
    std::cout << "\rScanlines remaining: " << row << ' ' << std::flush;
    for (int col = 0; col < imageWidth; col++) {
      auto red = double(col) / (imageWidth - 1);
      auto green = double(row) / (imageHeight - 1);
      auto blue = 0.25;

      pixels[i++] = static_cast<unsigned char>(255.0 * red);
      pixels[i++] = static_cast<unsigned char>(255.0 * green);
      pixels[i++] = static_cast<unsigned char>(255.0 * blue);
    }
  }

  std::string outputDir = std::filesystem::current_path() / "image.png";
  stbi_write_png(outputDir.c_str(), imageWidth, imageHeight, numChannels, pixels, imageWidth * numChannels);

  std::cout << "\nDone.\n";
}

