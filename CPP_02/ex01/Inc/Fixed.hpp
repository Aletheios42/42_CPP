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
        Fixed(const Fixed& other);
        Fixed& operator=(const Fixed& other);
        ~Fixed();
        int getRawBits( void ) const;
        void setRawBits( int const raw );

        Fixed(const int value);
        Fixed(const float value);
        float toFloat() const;
        int toInt() const;

    private:
        int _rawValue;
        static const int _fractionalBits = 8;
};

std::ostream    &operator<<(std::ostream &out, Fixed const &fixed);
