#include "Point.hpp"
#include <cmath>

// sign / area helper using floats (via Fixed::toFloat)
static float sign(const Point& p1, const Point& p2, const Point& p3) {
    float x1 = p1.getX().toFloat();
    float y1 = p1.getY().toFloat();
    float x2 = p2.getX().toFloat();
    float y2 = p2.getY().toFloat();
    float x3 = p3.getX().toFloat();
    float y3 = p3.getY().toFloat();

    return (x1 - x3) * (y2 - y3) - (y1 - y3) * (x2 - x3);
}

bool bsp( Point const a, Point const b, Point const c, Point const point) {
    const float EPS = 1e-7f;

    float d1 = sign(point, a, b);
    float d2 = sign(point, b, c);
    float d3 = sign(point, c, a);

    // si está en un borde o en un vértice -> false
    if (fabs(d1) < EPS || fabs(d2) < EPS || fabs(d3) < EPS)
        return false;

    bool has_neg = (d1 < 0.0f) || (d2 < 0.0f) || (d3 < 0.0f);
    bool has_pos = (d1 > 0.0f) || (d2 > 0.0f) || (d3 > 0.0f);

    return !(has_neg && has_pos);
}