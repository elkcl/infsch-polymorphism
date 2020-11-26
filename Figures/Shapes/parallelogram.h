//
// Created by elk on 11/22/20.
//

#ifndef POLYMORPHISM_PARALLELOGRAM_H
#define POLYMORPHISM_PARALLELOGRAM_H

#include "polygon.h"
#include <iostream>
#include <memory>
#include <cassert>

class Parallelogram : public Polygon {
protected:
    double m_length, m_height;
public:
    Parallelogram(Point p1, Point p2, Point p3, Point p4): Polygon(std::vector<Point>{p1, p2, p3, p4}) {
        m_length = (p4 - p1).absv();
        double l = (p2 - p1) * (p4 - p1);
        m_height = std::sqrt((p2 - p1) * (p2 - p1) - l * l);
    }
    double length() const { return m_length; }
    double height() const { return m_height; }

    double diameter() const override;
    double perimeter() const override;
    double area() const override;

    static std::unique_ptr<Parallelogram> input(std::istream& in, std::ostream& out);
};

#endif //POLYMORPHISM_PARALLELOGRAM_H
