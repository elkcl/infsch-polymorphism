//
// Created by elk on 11/22/20.
//

#ifndef POLYMORPHISM_CYLINDER_H
#define POLYMORPHISM_CYLINDER_H

#include "prism.h"
#include "circle.h"

class Cylinder : public Prism<Circle> {
public:
    double diameter() const override;
};

#endif //POLYMORPHISM_CYLINDER_H
