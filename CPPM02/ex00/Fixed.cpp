#include <iostream>
#include "Fixed.hpp"


// Constructor por defecto: inicializa nvalue a 0
Fixed::Fixed() : nvalue(0) {
    std::cout << "Default constructor called" << std::endl;
}

// Constructor desde int
Fixed::Fixed(int n) : nvalue(n) {
    std::cout << "Int constructor called" << std::endl;
}

// Constructor por copia: copia el valor interno
Fixed::Fixed(const Fixed& copy) : nvalue(copy.nvalue) {
    std::cout << "Copy constructor called" << std::endl;
}

// Operador de asignación por copia: protege self-assignment y copia
Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->nvalue = other.nvalue;
    }
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called" << std::endl;
    return nvalue;
}

void Fixed::setRawBits(int rawBits)
{
    std::cout << "setRawBits member function called" << std::endl;
    nvalue = rawBits;
}
