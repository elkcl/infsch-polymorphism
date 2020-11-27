//
// Created by elk on 11/22/20.
//

#include "square.h"

double Square::diameter() const {
    return SQRT2 * m_length;
}

double Square::perimeter() const {
    return 4 * m_length;
}

double Square::area() const {
    return m_length * m_length;
}

std::unique_ptr<Square> Square::input(std::istream& in, std::ostream& out) {
    out << "square (point & 2 vectors)\n";
    double x, y, z;

    out << "Point:\n";
    in >> x >> y >> z;
    Point p{x, y, z};
    out << "Vector 1:\n";
    in >> x >> y >> z;
    Point v1{x, y, z};
    out << "Vector 2:\n";
    in >> x >> y >> z;
    Point v2{x, y, z};

    assert(v1 * v2 == 0);
    assert(v1.absv() == v2.absv());

    return std::make_unique<Square>(p, p + v1, p + v1 + v2, p + v2);
}