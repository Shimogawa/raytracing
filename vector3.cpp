#include "vector3.h"

#include "vector3.h"

std::istream& operator>>(std::istream& is, vector3& t) {
    is >> t.x >> t.y >> t.z;
    return is;
}

std::ostream& operator<<(std::ostream& os, const vector3& t) {
    os << "<" << t.x << ", " << t.y << ", " << t.z << ">";
    return os;
}
