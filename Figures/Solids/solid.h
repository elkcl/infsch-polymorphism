//
// Created by elk on 11/22/20.
//

#ifndef POLYMORPHISM_SOLID_H
#define POLYMORPHISM_SOLID_H

class Solid {
public:
    virtual ~Solid() = default;

    virtual double diameter() const = 0;
    virtual double surfaceArea() const = 0;
    virtual double volume() const = 0;
};

#endif //POLYMORPHISM_SOLID_H
