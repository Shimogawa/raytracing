#include "main.h"

bool hit_sphere(const vector3& center, float radius, const ray& r) {
    vector3 oc = r.origin - center;
    float a = dot(r.direction, r.direction);
    float b = 2.0f * dot(oc, r.direction);
    float c = dot(oc, oc) - radius * radius;
    float delta = b * b - 4.0f * a * c;
    return delta > 0;
}

rgbcolor color(const ray& r) {
    if (hit_sphere(vec3(0,0,-1), 0.5, r))
        return rgbcolor::red();
    vector3 unit_dir = normalized(r.direction);
    float t = 0.5f * (unit_dir.y + 1.0f);
    return rgbcolor(lerp(
            vector3(.5f, .7f, 1.0f),
            vector3(1, 1, 1), t));
}

int main() {
    int width = 600;
    int height = 300;
    int channum = 3;

    int N = width * height * channum;
    auto buffer = new color_t[N];

    vector3 lower_left(-2, -1, -1);
    vector3 horiz_len(4, 0, 0);
    vector3 vert_len(0, 2, 0);
    vector3 origin(0, 0, 0);

    size_t idx = 0;
    for (int j = height - 1; j >= 0; --j) {
        for (int i = 0; i < width; i++) {
            float u = float(i) / float(width);
            float v = float(j) / float(height);
            ray r(origin, lower_left + u * horiz_len + v * vert_len);
            rgbcolor col = color(r);

            write_color(buffer, &idx, col);
        }
    }


    stbi_write_png("./output.png", width, height, channum, buffer, width * channum);
}