//
// Created by elk on 11/22/20.
//

#ifndef POLYMORPHISM_PRISM_H
#define POLYMORPHISM_PRISM_H

#include "point.h"
#include "shape.h"
#include "solid.h"
#include <type_traits>
#include <iostream>
#include <memory>
#include <cassert>

template <typename T>
class Prism;

template <typename T>
class PrismBase : public Solid {
    static_assert(std::is_base_of<Shape, T>::value, "Prism base must be a 2D shape");
protected:
    T m_base;
    Point m_transVector;
public:
    PrismBase(T base, Point transVector): m_base{base}, m_transVector{transVector} {}
    const T& base() const { return base; }
    const Point& transVector() const { return m_transVector; }

    double surfaceArea() const override {
        return 2 * m_base.area() + m_base.perimeter() * m_transVector.absv();
    }
    double volume() const override {
        Plane basePlane = m_base.plane();
        return m_base.area() * (basePlane.projection(basePlane.point() + m_transVector) - basePlane.point()).absv();
    }

    static std::unique_ptr<Prism<T>> input(std::istream& in, std::ostream& out) {
        auto b = T::input(in, out);
        double x, y, z;
        out << "Transition vector:\n";
        in >> x >> y >> z;
        Point tv{x, y, z};
        return std::make_unique<Prism<T>>(*b, tv);
    }
};

template <typename T>
class Prism : public PrismBase<T> {};

#endif //POLYMORPHISM_PRISM_H
