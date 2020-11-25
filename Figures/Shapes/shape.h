//
// Created by elk on 11/22/20.
//

#ifndef POLYMORPHISM_SHAPE_H
#define POLYMORPHISM_SHAPE_H

#include "plane.h"

class Shape {
protected:
    Plane m_plane;
public:
    explicit Shape(Plane plane): m_plane{plane} {}
    virtual ~Shape() = default;

    Plane plane() const { return m_plane; }

    virtual double diameter() const = 0;
    virtual double perimeter() const = 0;
    virtual double area() const = 0;
};

#endif //POLYMORPHISM_SHAPE_H
