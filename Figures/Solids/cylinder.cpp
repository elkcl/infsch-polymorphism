//
// Created by elk on 11/22/20.
//

#include "cylinder.h"

double Cylinder::diameter() const {
    Point centerLine = m_base.plane().projection(m_base.center() + m_transVector) - m_base.center();
    Point a = m_base.center() - m_base.radius() * (centerLine / centerLine.absv());
    Point b = m_base.center() + m_transVector + m_base.radius() * (centerLine / centerLine.absv());
    return (b - a).absv();
}