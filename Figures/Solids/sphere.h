//
// Created by elk on 11/22/20.
//

#ifndef POLYMORPHISM_SPHERE_H
#define POLYMORPHISM_SPHERE_H

#include "solid.h"
#include "point.h"
#include <iostream>
#include <memory>

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

    static std::unique_ptr<Sphere> input(std::istream& in, std::ostream& out);
};

#endif //POLYMORPHISM_SPHERE_H
