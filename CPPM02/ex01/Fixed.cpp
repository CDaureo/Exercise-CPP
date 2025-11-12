#include "Fixed.hpp"

Fixed::Fixed() : nvalue(0){
        std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int n) : nvalue(n << Fixed::maxBits){
    std::cout << "Int constructor called" << std::endl;
}
Fixed::Fixed(float f) {
    // convertir float a raw fixed-point (redondeo)
    nvalue = (std::roundf(f * (1 << Fixed::maxBits)));
    std::cout << "Float constructor called" << std::endl;
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
    std::cout << "Destruction called" << std::endl;
    
}

// funcion no miembro que permite usar: std::cout << obj;
std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
    // Llama a toFloat() del objeto Fixed para obtener su representacion en punto flotante
    // y la inserta en el stream `os` usando el operador << de std::ostream.
    os << obj.toFloat();

    // Devuelve el mismo stream por referencia para permitir el encadenamiento:
    // std::cout << a << b; (el resultado de `std::cout << a` debe ser el stream).
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