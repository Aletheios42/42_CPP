#pragma once

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <sstream>
#include <cmath>

// En Fixed.hpp
class Fixed {
    public:
        Fixed();
        Fixed(const int value);
        Fixed(const float value);
        Fixed(const Fixed& other);
        Fixed& operator=(const Fixed& other);
        ~Fixed();

        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat() const;
        int toInt() const;

        //ADD

        Fixed operator+(Fixed const &fixed);
        Fixed operator-(Fixed const &fixed);
        Fixed operator*(Fixed const &fixed);
        Fixed operator/(Fixed const &fixed);

        bool operator==(Fixed const &fixed) const;
        bool operator!=(Fixed const &fixed) const;
        bool operator<(Fixed const &fixed) const;
        bool operator<=(Fixed const &fixed) const;
        bool operator>(Fixed const &fixed) const;
        bool operator>=(Fixed const &fixed) const;

        Fixed& operator++();
        Fixed operator++(int);
        Fixed& operator--();
        Fixed operator--(int);

        static Fixed &min(Fixed &f1, Fixed&f2);
        static const Fixed &min(const Fixed &f1, const Fixed&f2);
        static Fixed &max(Fixed &f1, Fixed&f2);
        static const Fixed &max(const Fixed &f1,const Fixed&f2);
    private:
        int _rawValue;
        static const int _fractionalBits;
};

std::ostream    &operator<<(std::ostream &out, Fixed const &fixed);
// ADD
