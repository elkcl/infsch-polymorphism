//
// Created by elk on 11/22/20.
//

#include "circle.h"

double Circle::diameter() const {
    return m_radius * 2;
}
double Circle::perimeter() const {
    return 2 * PI * m_radius;
}
double Circle::area() const {
    return PI * m_radius * m_radius;
}

std::unique_ptr<Circle> Circle::input(std::istream& in, std::ostream& out) {
    out << "circle (center, radius & normal vector)\n";
    double x, y, z, r;

    out << "Center:\n";
    in >> x >> y >> z;
    Point p{x, y, z};
    out << "Radius:\n";
    in >> r;
    out << "Normal:\n";
    in >> x >> y >> z;
    Point n{x, y, z};

    return std::make_unique<Circle>(p, r, Plane{p, n});
}