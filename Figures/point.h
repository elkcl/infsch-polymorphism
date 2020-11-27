//
// Created by elk on 11/22/20.
//

#ifndef POLYMORPHISM_POINT_H
#define POLYMORPHISM_POINT_H

#include <cmath>

const double PI = std::acos(-1);
const double SQRT2 = std::sqrt(2);
const double SQRT3 = std::sqrt(3);

class Point {
public:
    double x = 0;
    double y = 0;
    double z = 0;

    Point operator-() const {
        return Point{-x, -y, -z};
    }
    Point& operator+=(const Point& p) {
        x += p.x;
        y += p.y;
        z += p.z;
        return *this;
    }
    double absv() const;
};

inline Point operator+(const Point& a, const Point& b) {
    return Point{a.x + b.x, a.y + b.y, a.z + b.z};

}
inline Point operator-(const Point& a, const Point& b) {
    return Point{a.x - b.x, a.y - b.y, a.z - b.z};

}
inline Point operator*(const Point& a, double k) { // умножение вектора на скаляр
    return Point{a.x*k, a.y*k, a.z*k};
}
inline Point operator*(double k, const Point& a) { // умножение вектора на скаляр
    return Point{a.x*k, a.y*k, a.z*k};
}
inline Point operator/(const Point& a, double k) { // деление вектора на скаляр
    return Point{a.x/k, a.y/k, a.z/k};
}
inline double operator*(const Point& a, const Point& b) { // скалярное произведение
    return a.x * b.x + a.y * b.y + a.z * b.z;
}
inline Point operator%(const Point& a, const Point& b) { // векторное произведение
    return Point{a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x};
}

inline double Point::absv() const {
    return std::sqrt((*this) * (*this));
}

#endif //POLYMORPHISM_POINT_H
