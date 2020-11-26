//
// Created by elk on 11/22/20.
//

#include "sphere.h"

double Sphere::diameter() const {
    return 2 * m_radius;
}

double Sphere::surfaceArea() const {
    return 4 * PI * m_radius * m_radius;
}

double Sphere::volume() const {
    return 4 * PI * m_radius * m_radius * m_radius / 3;
}

std::unique_ptr<Sphere> Sphere::input(std::istream& in, std::ostream& out) {
    out << "sphere (center & radius)\n";
    double x, y, z, r;

    out << "Center:\n";
    in >> x >> y >> z;
    Point p{x, y, z};
    out << "Radius:\n";
    in >> r;

    return std::make_unique<Sphere>(p, r);
}