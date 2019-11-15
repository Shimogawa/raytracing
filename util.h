#ifndef RAYTRACING_UTIL_H
#define RAYTRACING_UTIL_H

#include <cstdio>
#include "vector3.h"

void print_arr(void* data, size_t num_elem);
inline vector3 lerp(const vector3& start, const vector3& end, float t) {
    return start * t + end * (1 - t);
}

#endif //RAYTRACING_UTIL_H
