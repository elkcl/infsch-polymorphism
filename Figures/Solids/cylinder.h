//
// Created by elk on 11/22/20.
//

#ifndef POLYMORPHISM_CYLINDER_H
#define POLYMORPHISM_CYLINDER_H

#include "prism.h"
#include "circle.h"

template<>
class Prism<Circle> : public PrismBase<Circle> {
public:
    double diameter() const override {
        Point centerLine = m_base.plane().projection(m_base.center() + m_transVector) - m_base.center();
        Point a = m_base.center() - m_base.radius() * (centerLine / centerLine.absv());
        Point b = m_base.center() + m_transVector + m_base.radius() * (centerLine / centerLine.absv());
        return (b - a).absv();
    }

    static std::unique_ptr<Prism<Circle>> input(std::istream& in, std::ostream& out) {
        out << "cylinder (circle & transition vector)\n";
        return PrismBase<Circle>::input(in, out);
    }
};

using Cylinder = Prism<Circle>;

#endif //POLYMORPHISM_CYLINDER_H
