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