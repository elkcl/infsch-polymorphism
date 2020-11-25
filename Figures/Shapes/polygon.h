//
// Created by elk on 11/22/20.
//
#ifndef POLYMORPHISM_POLYGON_H
#define POLYMORPHISM_POLYGON_H

#include "shape.h"
#include "point.h"
#include "plane.h"
#include <vector>

class Polygon : public Shape {
protected:
    int m_vertexCount;
    std::vector<Point> m_verteces; // вершины в порядке обхода против часовой
public:
    explicit Polygon(const std::vector<Point> &verteces): Shape{Plane{verteces.at(0), verteces.at(1), verteces.at(2)}}, m_vertexCount{static_cast<int>(verteces.size())}, m_verteces{verteces} {}
    int vertexCount() const { return m_vertexCount; }
    const std::vector<Point>& verteces() const { return m_verteces; }

    double diameter() const override;
    double perimeter() const override;
    double area() const override;
};

#endif //POLYMORPHISM_POLYGON_H
