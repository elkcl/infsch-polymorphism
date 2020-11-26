//
// Created by elk on 11/26/20.
//

#ifndef POLYMORPHISM_CUBE_H
#define POLYMORPHISM_CUBE_H

#include "prism.h"
#include "square.h"
#include <cmath>

const double SQRT3 = std::sqrt(3);

template<>
class Prism<Square> : public PrismBase<Square> {
private:
    double a = m_base.length();
public:
    double diameter() const override {
        return SQRT3 * a;
    }
    double surfaceArea() const override {
        return 6 * a * a;
    }
    double volume() const override {
        return a * a * a;
    }

    static std::unique_ptr<Prism<Square>> input(std::istream& in, std::ostream& out) {
        out << "cube (square & transition vector)\n";
        auto solid = PrismBase<Square>::input(in, out);
        Point v1 = solid -> m_base.plane().normal();
        Point tv = solid -> m_transVector;
        double l = solid -> m_base.length();
        assert((v1 % tv).absv() == 0);
        assert(l == tv.absv());
        return solid;
    }
};

using Cube = Prism<Square>;

#endif //POLYMORPHISM_CUBE_H
