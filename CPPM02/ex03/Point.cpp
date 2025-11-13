#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(float nx, float ny) : x(nx), y(ny) {}

Point::Point(const Point& other) : x(other.x), y(other.y) {}

Point& Point::operator=(const Point& other) {
    (void)other; // no se pueden asignar miembros const; operator= se deja disponible pero no altera los miembros
    return *this;
}

Point::~Point() {}

const Fixed& Point::getX() const { return x; }
const Fixed& Point::getY() const { return y; }

