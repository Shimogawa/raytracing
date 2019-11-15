#ifndef RAYTRACING_RGBCOLOR_H
#define RAYTRACING_RGBCOLOR_H

#include <cstdint>
#include "vector3.h"

typedef uint8_t     color_t;

#define COLOR_0     ((color_t)   0)
#define COLOR_255   ((color_t) 255)
#define COLOR_MAX   COLOR_255


class rgbcolor {
private:
    rgbcolor() = default;
    color_t rgb[3] { };

public:

    explicit rgbcolor(const vector3& v);
    rgbcolor(color_t r, color_t g, color_t b);
    rgbcolor(float fr, float fg, float fb);

    color_t r() const;
    color_t g() const;
    color_t b() const;

    static rgbcolor fromvector(const vector3& v);
    static rgbcolor fromfloat(float fr, float fg, float fb);

    static rgbcolor black();
    static rgbcolor white();
    static rgbcolor red();

};

void write_color(color_t *buffer, size_t *idx, const rgbcolor& color);


#endif //RAYTRACING_RGBCOLOR_H
