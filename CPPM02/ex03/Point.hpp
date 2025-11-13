#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
public:
    Point();
    Point(float x, float y);
    Point(const Point& other);
    Point& operator=(const Point& other);
    ~Point();

    const Fixed& getX() const;
    const Fixed& getY() const;

private:
    const Fixed x;
    const Fixed y;
};

#endif // POINT_HPP