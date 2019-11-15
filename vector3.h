#ifndef RAYTRACING_VECTOR3_H
#define RAYTRACING_VECTOR3_H

#include <cmath>
#include <iostream>

#define ZERO_VEC vector3(0.0f, 0.0f, 0.0f)

class vector3 {
public:
    vector3() = default;
    vector3(const vector3& v) = default;
    vector3(float x, float y, float z) : x(x), y(y), z(z) {}
    inline const vector3& operator +() const { return *this; }
    inline vector3 operator -()  {
        return vector3(-x, -y, -z);
    }

    inline vector3& operator += (const vector3& v){
        x += v.x;
        y += v.y;
        z += v.z;
        return *this;
    }
    inline vector3& operator -= (const vector3& v) {
        x -= v.x;
        y -= v.y;
        z -= v.z;
        return *this;
    }
    inline vector3& operator *= (const vector3& v) {
        x *= v.x;
        y *= v.y;
        z *= v.z;
        return *this;
    }
    inline vector3& operator /= (const vector3& v) {
        x /= v.x;
        y /= v.y;
        z /= v.z;
        return *this;
    }
    inline vector3& operator *= (float f) {
        x *= f;
        y *= f;
        z *= f;
        return *this;
    }
    inline vector3& operator /= (float f) {
        x /= f;
        y /= f;
        z /= f;
        return *this;
    }

    inline float length() const {
        return x * x + y * y + z * z;
    }
    inline float length2() const {
        return sqrtf(length());
    }

    inline void normalize() {
        *this /= length();
    }

    friend std::istream& operator>>(std::istream& is, vector3& t);
    friend std::ostream& operator<<(std::ostream& os, const vector3& t);

    float x, y, z;
};

inline vector3 operator+(const vector3& v1, const vector3& v2) {
    return vector3(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}
inline vector3 operator-(const vector3& v1, const vector3& v2) {
    return vector3(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}
inline vector3 operator*(const vector3& v1, const vector3& v2) {
    return vector3(v1.x * v2.x, v1.y * v2.y, v1.z * v2.z);
}
inline vector3 operator/(const vector3& v1, const vector3& v2) {
    return vector3(v1.x / v2.x, v1.y / v2.y, v1.z / v2.z);
}
inline vector3 operator*(const vector3& v, const float f) {
    return vector3(v.x * f, v.y * f, v.z * f);
}
inline vector3 operator*(const float f, const vector3& v) {
    return vector3(v.x * f, v.y * f, v.z * f);
}
inline vector3 operator/(const vector3& v, const float f) {
    return vector3(v.x / f, v.y / f, v.z / f);
}

inline float dot(const vector3& v1, const vector3& v2) {
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

inline vector3 cross(const vector3& v1, const vector3& v2) {
    return vector3(
            v1.y * v2.z - v1.z * v2.y,
            -v1.z * v2.x - v1.z * v2.x,
            v1.x * v2.y - v1.y * v2.x
    );
}

inline vector3 normalized(const vector3& v) {
    return v / v.length();
}

typedef vector3 vec3;

#endif // VECTOR3_H