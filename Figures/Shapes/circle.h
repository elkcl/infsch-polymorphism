//
// Created by elk on 11/22/20.
//

#ifndef POLYMORPHISM_CIRCLE_H
#define POLYMORPHISM_CIRCLE_H

#include "shape.h"
#include "point.h"
#include <cmath>
#include <iostream>
#include <memory>

const double PI = std::acos(-1);

class Circle : public Shape {
private:
    Point m_center;
    double m_radius;
public:
    Circle(Point center, double radius, Plane plane): Shape{plane}, m_center{center}, m_radius{radius} {}
    Point center() const { return m_center; }
    double radius() const { return m_radius; }

    double diameter() const override;
    double perimeter() const override;
    double area() const override;

    static std::unique_ptr<Circle> input(std::istream& in, std::ostream& out);
};

#endif //POLYMORPHISM_CIRCLE_H
