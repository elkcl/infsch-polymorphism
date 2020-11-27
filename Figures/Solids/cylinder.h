//
// Created by elk on 11/22/20.
//

#ifndef POLYMORPHISM_CYLINDER_H
#define POLYMORPHISM_CYLINDER_H

#include <utility>

#include "prism.h"
#include "circle.h"

template<>
class Prism<Circle> : public PrismBase<Circle> {
public:
    Prism(Circle base, Point transVector): PrismBase<Circle>{std::move(base), transVector} {}
    double diameter() const override {
        Point centerLine = m_base.plane().projection(m_base.center() + m_transVector) - m_base.center();
        if (centerLine.absv() != 0) centerLine = centerLine / centerLine.absv();
        Point a = m_base.center() - m_base.radius() * centerLine;
        Point b = m_base.center() + m_transVector + m_base.radius() * centerLine;
        return (b - a).absv();
    }

    static std::unique_ptr<Prism<Circle>> input(std::istream& in, std::ostream& out) {
        out << "cylinder (circle & transition vector)\n";
        return PrismBase<Circle>::input(in, out);
    }
};

using Cylinder = Prism<Circle>;

#endif //POLYMORPHISM_CYLINDER_H
