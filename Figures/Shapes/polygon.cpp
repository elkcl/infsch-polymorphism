//
// Created by elk on 11/22/20.
//

#include "polygon.h"

double Polygon::diameter() const {
    double ans = 0;
    for (int i = 0; i < m_vertexCount-1; ++i) {
        for (int j = i + 1; j < m_vertexCount; ++j) {
            double d = (m_verteces[i] - m_verteces[j]).absv();
            ans = d > ans ? d : ans;
        }
    }
    return ans;
}

double Polygon::perimeter() const {
    double p = 0;
    for (int i = 0; i < m_vertexCount-1; ++i) {
        p += (m_verteces[i] - m_verteces[i+1]).absv();
    }
    p += (m_verteces[m_vertexCount-1] - m_verteces[0]).absv();
    return p;
}

double Polygon::area() const {
    double s = 0;
    for (int i = 0; i < m_vertexCount-1; ++i) {
        s += (m_verteces[i] % m_verteces[i+1]).absv();
    }
    s += m_verteces[m_vertexCount-1] % m_verteces[0] * m_plane.normal();
    return std::abs(s / 2);
}