//
// Created by elk on 11/22/20.
//

#include "rectangle.h"

double Rectangle::diameter() const {
    return sqrt(m_length*m_length + m_height*m_height);
}

double Rectangle::perimeter() const {
    return 2 * (m_length + m_height);
}

std::unique_ptr<Rectangle> Rectangle::input(std::istream& in, std::ostream& out) {
    out << "rectangle (point & 2 vectors)\n";
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

    return std::make_unique<Rectangle>(p, p + v1, p + v1 + v2, p + v2);
}