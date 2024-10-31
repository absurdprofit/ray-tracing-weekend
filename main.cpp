#include "main.h"
#include "camera.h"
#include "hittable.h"
#include "hittable_list.h"
#include "material.h"
#include "sphere.h"

int main() {
  camera camera;
  hittable_list world;

  auto material_ground = make_shared<lambertian>(colour(0.8, 0.8, 0.0));
  auto material_centre = make_shared<lambertian>(colour(0.1, 0.2, 0.5));
  auto material_left = make_shared<metal>(colour(0.8, 0.8, 0.8));
  auto material_right = make_shared<metal>(colour(0.8, 0.6, 0.2));
  // auto material_vanta_black = make_shared<vanta_black>();

  world.add(make_shared<sphere>(point3(0.0, -100.5, -1.0), 100.0, material_ground));
  world.add(make_shared<sphere>(point3(0.0, 0.0, -1.2), 0.5, material_centre));
  world.add(make_shared<sphere>(point3(-1.0, 0.0, -1.0), 0.5, material_left));
  world.add(make_shared<sphere>(point3(1.0, 0.0, -1.0), 0.5, material_right));
  // world.add(make_shared<sphere>(point3(2.0, 0.5, -2.0), 0.5, material_vanta_black));

  camera.image_width = 1920;
  camera.samples_per_pixel = 100;
  camera.max_depth = 50;

  camera.render(world);
}