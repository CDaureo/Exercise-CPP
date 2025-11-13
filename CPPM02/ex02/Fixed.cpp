#include "Fixed.hpp"

Fixed::Fixed() : _raw(0){}

Fixed::Fixed(const int n) : _raw(n << Fixed::_fractionalBits){
    std::cout << "Int constructor called" << std::endl;
}
Fixed::Fixed(const float f) {
    // convertir float a raw fixed-point (redondeo)
    _raw = (roundf(f * (1 << Fixed::_fractionalBits)));
    std::cout << "Float constructor called" << std::endl;
}
Fixed::Fixed(const Fixed& other) : _raw(other._raw){}

Fixed::~Fixed(){
        std::cout << "Destructor called" << std::endl;

}

Fixed& Fixed::operator=(const Fixed& other)
{
    if (this != &other)
    {
        this->_raw = other._raw;
    }
    return *this;
}
int Fixed::getRawBits() const{
    return _raw;
}

void Fixed::setRawBits(int raw){
    this->_raw = raw;
}
bool Fixed::operator>(const Fixed& other) const {
    return this->_raw > other._raw;
}
bool Fixed::operator<(const Fixed& other) const {
    return this->_raw < other._raw;
}
bool Fixed::operator>=(const Fixed& other) const {
    return this->_raw >= other._raw;
}
bool Fixed::operator<=(const Fixed& other) const {
    return this->_raw <= other._raw;
}
bool Fixed::operator==(const Fixed& other) const {
    return this->_raw == other._raw;
}
bool Fixed::operator!=(const Fixed& other) const {
    return this->_raw != other._raw;
}
Fixed Fixed::operator+(const Fixed& other) const {
    Fixed result;
    result.setRawBits(this->_raw + other._raw);
    return result;
}
Fixed Fixed::operator-(const Fixed& other) const {
    Fixed result;
    result.setRawBits(this->_raw - other._raw);
    return result;
}
Fixed Fixed::operator*(const Fixed& other) const {
    Fixed res;
    long long tmp = (long long)this->_raw * (long long)other._raw;
    tmp >>= Fixed::_fractionalBits; // ajustar la escala (equivalente a dividir por 2^f)
    res.setRawBits((int)tmp);
    return res;
}
Fixed Fixed::operator/(const Fixed& other) const {
    Fixed res;
    long long num = ((long long)this->_raw << Fixed::_fractionalBits); // escalar antes de dividir
    res.setRawBits((int)(num / other._raw));
    return res;
}


Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    if (a <= b)
    {
        return a;
    }
    return b;
    
}
Fixed& Fixed::operator++()
{
    ++_raw;            // incrementa en la mínima ϵ
    return *this;
} 
Fixed& Fixed::operator--()
{
    --_raw;            // decrementa en la mínima ϵ
    return *this;
} 
Fixed Fixed::operator++(int)
{   Fixed tmp(*this);
    ++_raw;
    return tmp;
} 
Fixed Fixed::operator--(int)
{   Fixed tmp(*this);
    --_raw;
    return tmp;
} 
const Fixed& Fixed::min(const Fixed& a,const Fixed& b)
{
    if (a <= b)
    {
        return a;
    }
    return b;
    
}
Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    if (a >= b)
    {
        return a;
    }
    return b;
    
}
const Fixed& Fixed::max(const Fixed& a,const Fixed& b)
{
    if (a >= b)
    {
        return a;
    }
    return b;
    
}
float Fixed::toFloat( void ) const
{   
    return _raw / (1 << Fixed::_fractionalBits);
}
int Fixed::toInt( void ) const
{
    return static_cast<int>(_raw) >> static_cast<int>(Fixed::_fractionalBits);
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
    os << obj.toFloat();
    return os;
}