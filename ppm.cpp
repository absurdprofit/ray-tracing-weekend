#include <iostream>
#include "colour.h"
#include "vec3.h"

int toPPM(const colour[]& pixels, int image_width, double aspect_ratio) {
  int image_height = int(image_width / aspect_ratio);
  if (image_height < 1) {
    image_width = aspect_ratio;
    image_height = 1;
  }

  auto viewport_height = 2.0;
  auto viewport_width = viewport_height * (double(image_width) / image_height);

  std::cout << "P3\n" << image_width << ' ' << image_height << ' ' << "\n255\n";

  for (int j = 0; j < image_height; j++) {
    auto percentage = (double(j) / (image_height - 1)) * 100;
    std::clog << "\rScanlines remaining: " << percentage << '%' << std::flush;
    for (int i = 0; i < image_width; i++) {
      auto pixel_colour = colour(
        double(i) / (image_width - 1),
        double(j) / (image_height - 1),
        0
      );
      
      write_colour(std::cout, pixel_colour);
    }
  }
}