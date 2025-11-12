#include <iostream>
#include "Fixed.hpp"


int main( void ) {
    Fixed a; //Llama al constructor por defecto
    Fixed b( a ); //Llama a Fixed::Fixed(const Fixed&)
    Fixed c; //Llama al constructor por defecto
    c = b; //Crea una asignación: se invoca Fixed::operator=(const Fixed& other)
    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;
    return 0;
}