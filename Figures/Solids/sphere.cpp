//
// Created by elk on 11/22/20.
//

#include "sphere.h"

double Sphere::diameter() const {
    return 2 * m_radius;
}

double Sphere::surfaceArea() const {
    return 4 * PI * m_radius * m_radius;
}

double Sphere::volume() const {
    return 4 * PI * m_radius * m_radius * m_radius / 3;
}