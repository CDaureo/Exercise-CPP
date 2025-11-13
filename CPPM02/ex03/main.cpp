#include <iostream>
#include "Point.hpp"

// declaración de bsp
bool bsp( Point const a, Point const b, Point const c, Point const point);

int main() {
    Point a(0.f, 0.f);
    Point b(10.f, 0.f);
    Point c(0.f, 10.f);

    Point p1(1.f, 1.f);      // dentro -> true
    Point p2(0.f, 0.f);      // vértice -> false
    Point p3(5.f, 0.f);      // borde -> false
    Point p4(10.1f, 10.1f);  // fuera -> false

    std::cout << std::boolalpha;
    std::cout << "p1 inside: " << bsp(a,b,c,p1) << std::endl;
    std::cout << "p2 inside: " << bsp(a,b,c,p2) << std::endl;
    std::cout << "p3 inside: " << bsp(a,b,c,p3) << std::endl;
    std::cout << "p4 inside: " << bsp(a,b,c,p4) << std::endl;

    return 0;
}