#include "rgbcolor.h"

rgbcolor::rgbcolor(color_t r, color_t g, color_t b) {
    rgb[0] = r;
    rgb[1] = g;
    rgb[2] = b;
}

rgbcolor::rgbcolor(float fr, float fg, float fb)
    : rgbcolor(color_t(255.99f * fr),
               color_t(255.99f * fg),
               color_t(255.99f * fb)) { }

rgbcolor::rgbcolor(const vector3 &v) : rgbcolor(v.x, v.y, v.z) { }

color_t rgbcolor::r() const {
    return rgb[0];
}

color_t rgbcolor::g() const {
    return rgb[1];
}

color_t rgbcolor::b() const {
    return rgb[2];
}

rgbcolor rgbcolor::fromvector(const vector3& v) {
    return rgbcolor(v);
}

rgbcolor rgbcolor::fromfloat(float fr, float fg, float fb) {
    return rgbcolor(fr, fg, fb);
}

rgbcolor rgbcolor::black() {
    return rgbcolor(COLOR_0, COLOR_0, COLOR_0);
}

rgbcolor rgbcolor::white() {
    return rgbcolor(COLOR_MAX, COLOR_MAX, COLOR_MAX);
}

rgbcolor rgbcolor::red() {
    return rgbcolor(COLOR_MAX, COLOR_0, COLOR_0);
}

void write_color(color_t *buffer, size_t *idx, const rgbcolor& color) {
    buffer[(*idx)++] = color.r();
    buffer[(*idx)++] = color.g();
    buffer[(*idx)++] = color.b();
}
