//
// Created by elk on 11/22/20.
//

#include "circle.h"

double Circle::diameter() const {
    return m_radius * 2;
}
double Circle::perimeter() const {
    return 2 * PI * m_radius;
}
double Circle::area() const {
    return PI * m_radius * m_radius;
}