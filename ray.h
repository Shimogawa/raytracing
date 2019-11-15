#ifndef RAYTRACING_RAY_H
#define RAYTRACING_RAY_H

#include "vector3.h"

class ray {
public:
    ray() {}
    ray(const vector3& origin, const vector3& direction) : origin(origin), direction(direction) {}

    vector3 point_at_time(float t) const {
        return origin + t * direction;
    }

    vector3 origin, direction;
};

#endif
