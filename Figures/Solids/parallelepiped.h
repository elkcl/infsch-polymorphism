//
// Created by elk on 11/22/20.
//

#ifndef POLYMORPHISM_PARALLELEPIPED_H
#define POLYMORPHISM_PARALLELEPIPED_H

#include <utility>

#include "prism.h"
#include "parallelogram.h"

template<>
class Prism<Parallelogram> : public PrismBase<Parallelogram> {
public:
    Prism(Parallelogram base, Point transVector): PrismBase<Parallelogram>{std::move(base), transVector} {}
    double diameter() const override {
        double a = (m_base.verteces()[3] + m_transVector - m_base.verteces()[1]).absv();
        double b = (m_base.verteces()[2] + m_transVector - m_base.verteces()[0]).absv();
        return a > b ? a : b;
    }

    static std::unique_ptr<Prism<Parallelogram>> input(std::istream& in, std::ostream& out) {
        out << "parallelepiped (parallelogram & transition vector)\n";
        return PrismBase<Parallelogram>::input(in, out);
    }
};

using Parallelepiped = Prism<Parallelogram>;

#endif //POLYMORPHISM_PARALLELEPIPED_H
