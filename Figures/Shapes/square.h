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
    double diameter() const override;
    double perimeter() const override;
    double area() const override;
};

#endif //POLYMORPHISM_SQUARE_H
