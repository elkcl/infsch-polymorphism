//
// Created by elk on 11/22/20.
//

#ifndef POLYMORPHISM_PARALLELEPIPED_H
#define POLYMORPHISM_PARALLELEPIPED_H

#include "prism.h"
#include "parallelogram.h"

class Parallelepiped : public Prism<Parallelogram> {
public:
    double diameter() const override;
};

#endif //POLYMORPHISM_PARALLELEPIPED_H
