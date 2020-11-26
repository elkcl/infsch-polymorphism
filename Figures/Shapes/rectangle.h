//
// Created by elk on 11/22/20.
//

#ifndef POLYMORPHISM_RECTANGLE_H
#define POLYMORPHISM_RECTANGLE_H

#include "parallelogram.h"

class Rectangle : public Parallelogram {
public:
    Rectangle(Point p1, Point p2, Point p3, Point p4): Parallelogram{p1, p2, p3, p4} {
        m_height = (p1 - p2).absv();
    }

    double diameter() const override;
    double perimeter() const override;

    static std::unique_ptr<Rectangle> input(std::istream& in, std::ostream& out);
};

#endif //POLYMORPHISM_RECTANGLE_H
