//
// Created by elk on 11/22/20.
//

#include "square.h"

double Square::diameter() const {
    return sqrt(2) * m_length;
}

double Square::perimeter() const {
    return 4 * m_length;
}

double Square::area() const {
    return m_length * m_length;
}