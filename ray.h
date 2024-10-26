#ifndef RAY_H
#define RAY_H

#include "vec3.h"

class ray {
  public:
    ray() {}

    ray(const point3& orig, const vec3& dir) : _origin(orig), _direction(dir) {}

    const point3& origin() const { return _origin; }
    const vec3& direction() const { return _direction; }

    point3 at(double t) const {
      return _origin + t * _direction;
    }

  private:
    point3 _origin;
    vec3 _direction;
};

#endif