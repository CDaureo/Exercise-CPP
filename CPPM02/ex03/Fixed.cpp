#include "Fixed.hpp"

Fixed::Fixed() : nvalue(0){
}

Fixed::Fixed(int n) : nvalue(n << Fixed::maxBits){
}
Fixed::Fixed(float f) {
    // convertir float a raw fixed-point (redondeo)
    nvalue = (roundf(f * (1 << Fixed::maxBits)));
}

Fixed::Fixed(const Fixed& val) : nvalue(val.nvalue){}

Fixed& Fixed::operator=(const Fixed& other)
{
    if (this != &other)
    {
        this->nvalue = other.nvalue;
    }
    return *this;
}


Fixed::~Fixed(){
    
}

// funcion no miembro que permite usar: std::cout << obj;
std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
        os << obj.toFloat();
    return os;
}

float Fixed::toFloat( void ) const
{   
    return nvalue / (1 << Fixed::maxBits);
}
int Fixed::toInt( void ) const
{
    return static_cast<int>(nvalue) >> static_cast<int>(Fixed::maxBits);
}