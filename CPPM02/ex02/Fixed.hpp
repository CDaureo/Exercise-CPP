#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
#include <iostream>

class Fixed {
    private:
        float _raw;
        static const int _fractionalBits = 8;
    public:
        Fixed();
        Fixed(const int n);
        Fixed(const float n);
        Fixed(const Fixed& other);
        ~Fixed();

        Fixed& operator=(const Fixed& other);
        
        // Comparison operators
        bool operator>(const Fixed& other) const;
        bool operator<(const Fixed& other) const;
        bool operator>=(const Fixed& other) const;
        bool operator<=(const Fixed& other) const;
        bool operator==(const Fixed& other) const;
        bool operator!=(const Fixed& other) const;

        // Arithmetic operators
        Fixed operator+(const Fixed& other) const;
        Fixed operator-(const Fixed& other) const;
        Fixed operator*(const Fixed& other) const;
        Fixed operator/(const Fixed& other) const;

        // Increment / Decrement
        Fixed& operator++();    // pre-increment
        Fixed operator++(int);  // post-increment
        Fixed& operator--();    // pre-decrement
        Fixed operator--(int);  // post-decrement

        // Raw access / conversion helpers
        int getRawBits() const;
        void setRawBits(int raw);
        float toFloat() const;
        int toInt() const;

        // min / max (overloads)
        static Fixed& min(Fixed& a, Fixed& b);
        static const Fixed& min(const Fixed& a, const Fixed& b);
        static Fixed& max(Fixed& a, Fixed& b);
        static const Fixed& max(const Fixed& a, const Fixed& b);
};
    
    
    std::ostream& operator<<(std::ostream& os, const Fixed& f);
    
#endif // FIXED_HPP