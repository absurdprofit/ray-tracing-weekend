# Ray Tracing in One Weekend — C++ Implementation
A small C++ ray tracer based on *Ray Tracing in One Weekend*.  
The project renders simple 3D scenes using spheres, materials, lighting approximation, antialiasing, depth of field, and recursive ray scattering.

## Features
- PPM image output
- Camera with configurable aspect ratio and field of view
- Antialiasing through multiple samples per pixel
- Diffuse, metal, and dielectric/glass materials
- Recursive ray scattering
- Gamma correction
- Depth of field / defocus blur
- Random scene generation

## Requirements

- C++17 or newer
- A C++ compiler such as:
  - `g++`
  - `clang++`
  - MSVC

## Build

Using `g++`:

```bash
g++ -O2 main.cpp -o main > image.ppm
```