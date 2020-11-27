//
// Created by elk on 11/26/20.
//

#ifndef POLYMORPHISM_RECT_PARALLELEPIPED_H
#define POLYMORPHISM_RECT_PARALLELEPIPED_H

#include "prism.h"
#include "rectangle.h"

template<>
class Prism<Rectangle> : public PrismBase<Rectangle> {
private:
    double a = m_base.length();
    double b = m_base.height();
    double c = m_transVector.absv();
public:
    Prism(Rectangle base, Point transVector): PrismBase<Rectangle>{std::move(base), transVector} {}
    double diameter() const override {
        return std::sqrt(a*a + b*b + c*c);
    }
    double surfaceArea() const override {
        return 2 * (a*b + b*c + c*a);
    }
    double volume() const override {
        return a * b * c;
    }

    static std::unique_ptr<Prism<Rectangle>> input(std::istream& in, std::ostream& out) {
        out << "rectangular parallelepiped (rectangle & transition vector)\n";
        auto solid = PrismBase<Rectangle>::input(in, out);
        Point v1 = solid -> m_base.plane().normal();
        Point tv = solid -> m_transVector;
        assert((v1 % tv).absv() == 0);
        return solid;
    }
};

using RectParallelepiped = Prism<Rectangle>;

#endif //POLYMORPHISM_RECT_PARALLELEPIPED_H
