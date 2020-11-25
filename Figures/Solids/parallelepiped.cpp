//
// Created by elk on 11/22/20.
//

#include "parallelepiped.h"

double Parallelepiped::diameter() const {
    double a = (m_base.verteces()[3] + m_transVector - m_base.verteces()[1]).absv();
    double b = (m_base.verteces()[2] + m_transVector - m_base.verteces()[0]).absv();
    return a > b ? a : b;
}