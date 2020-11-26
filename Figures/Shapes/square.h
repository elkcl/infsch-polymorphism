//
// Created by elk on 11/22/20.
//

#ifndef POLYMORPHISM_SQUARE_H
#define POLYMORPHISM_SQUARE_H

#include "rectangle.h"

class Square : public Rectangle {
private:
    using Rectangle::height;
    using Rectangle::m_height;
public:
    Square(Point p1, Point p2, Point p3, Point p4): Rectangle{p1, p2, p3, p4} {}

    double diameter() const override;
    double perimeter() const override;
    double area() const override;

    static std::unique_ptr<Square> input(std::istream& in, std::ostream& out);
};

#endif //POLYMORPHISM_SQUARE_H
