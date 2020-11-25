//
// Created by elk on 11/22/20.
//

#ifndef POLYMORPHISM_SPHERE_H
#define POLYMORPHISM_SPHERE_H

#include "solid.h"
#include "point.h"
#include <cmath>

const double PI = std::acos(-1);

class Sphere : public Solid {
protected:
    Point m_center;
    double m_radius;
public:
    Sphere(Point center, double radius): m_center{center}, m_radius{radius} {}
    Point center() const { return m_center; }
    double radius() const { return m_radius; }

    double diameter() const override;
    double surfaceArea() const override;
    double volume() const override;
};

#endif //POLYMORPHISM_SPHERE_H
