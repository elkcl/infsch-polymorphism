//
// Created by elk on 11/22/20.
//

#ifndef POLYMORPHISM_PLANE_H
#define POLYMORPHISM_PLANE_H

#include "point.h"

class Plane {
private:
    Point m_point;
    Point m_normal;
public:
    Plane(Point p, Point n): m_point{p}, m_normal{n / n.absv()} {}
    Plane(Point p1, Point p2, Point p3) {
        Point n = (p2 - p1) % (p3 - p1);
        m_point = p1;
        m_normal = n / n.absv();
    }
    Point point() const { return m_point; }
    Point normal() const { return m_normal; }

    bool contains(Point p) const {
        return (p - m_point) * m_normal == 0;
    }
    Point projection(Point p) const {
        return ((m_point - p) * m_normal) * m_normal + p;
    }
};

#endif //POLYMORPHISM_PLANE_H
