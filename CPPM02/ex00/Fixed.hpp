#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>

class Fixed {
    private:
        int nvalue;
        static const int bitsValue = 8;
    public:
        Fixed(); //Constructor por DEFAULT 
        Fixed(int nvalue); //Constructor ya existente pero este inicializa int
        Fixed(const Fixed& copy); //Constructor por copia
        Fixed& operator=(const Fixed& other); //Asignacion por copia
        ~Fixed(); //Destructor
        int getRawBits(void) const;
        void setRawBits(int const rawBits);
};
#endif