#ifndef RAYTRACING_HITTABLE_H
#define RAYTRACING_HITTABLE_H

#include "vector3.h"
#include "ray.h"

struct hit_record {
    float t;
    vector3 p;
    vector3 normal;
};

class hittable {
public:
    virtual bool hit(const ray& r, float t_min, float t_max, hit_record& rec) const = 0;
};


#endif //RAYTRACING_HITTABLE_H
