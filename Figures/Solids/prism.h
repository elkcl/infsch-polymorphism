//
// Created by elk on 11/22/20.
//

#ifndef POLYMORPHISM_PRISM_H
#define POLYMORPHISM_PRISM_H

#include "point.h"
#include "shape.h"
#include "solid.h"
#include <type_traits>

template <typename T>
class Prism : public Solid {
    static_assert(std::is_base_of<Shape, T>::value, "Prism base must be a 2D shape");
protected:
    T m_base;
    Point m_transVector;
public:
    Prism(T base, Point transVector): m_base{base}, m_transVector{transVector} {}
    const T& base() const { return base; }
    const Point& transVector() const { return m_transVector; }

    double surfaceArea() const override {
        return 2 * m_base.area() + m_base.perimeter() * m_transVector.absv();
    }
    double volume() const override {
        Plane basePlane = m_base.plane();
        return m_base.area() * (basePlane.projection(basePlane.point() + m_transVector) - basePlane.point()).absv();
    }
};

#endif //POLYMORPHISM_PRISM_H
