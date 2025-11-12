

#include <string>
#include <cmath>
#include <iostream>


class   Fixed{
    private:
        float nvalue;
        static const int maxBits = 8;
    public:
        Fixed();
        Fixed(float f);
        Fixed(int n);
        Fixed(const Fixed& val);
        Fixed& operator=(const Fixed& other);
        ~Fixed();
        float toFloat( void ) const;
        int toInt( void ) const;
};
// operador de inserción para imprimir la representación en punto flotante
std::ostream& operator<<(std::ostream& os, const Fixed& obj);//OVERLOADS