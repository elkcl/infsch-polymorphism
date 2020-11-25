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