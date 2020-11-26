//
// Created by elk on 11/22/20.
//

#include "parallelogram.h"

double Parallelogram::diameter() const {
    double a = (m_verteces[1] - m_verteces[3]).absv();
    double b = (m_verteces[0] - m_verteces[2]).absv();
    return a > b ? a : b;
}

double Parallelogram::perimeter() const {
    return 2 * ((m_verteces[0] - m_verteces[1]).absv() + m_length);
}
double Parallelogram::area() const {
    return m_length * m_height;
}

std::unique_ptr<Parallelogram> Parallelogram::input(std::istream& in, std::ostream& out) {
    out << "parallelogram (point & 2 vectors)\n";
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

    return std::make_unique<Parallelogram>(p, p + v1, p + v1 + v2, p + v2);
}