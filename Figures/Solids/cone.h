//
// Created by elk on 11/22/20.
//

#ifndef POLYMORPHISM_CONE_H
#define POLYMORPHISM_CONE_H

#include "solid.h"
#include "shape.h"
#include "point.h"
#include <type_traits>

template <typename T>
class Cone : public Solid {
    static_assert(std::is_base_of<Shape, T>::value, "Cone base must be a 2D shape");
protected:
    T m_base;
    Point m_vertex;
public:
    double volume() const override {
        return m_base.area() * (m_base.plane().projection(m_vertex) - m_vertex).absv() / 3;
    }
};

#endif //POLYMORPHISM_CONE_H
