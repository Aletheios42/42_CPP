#pragma once

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <sstream>


class Fixed {
    public:
        Fixed();
        Fixed(const Fixed& other);
        Fixed& operator=(const Fixed& other);
        ~Fixed();
        int getRawBits( void ) const;
        void setRawBits( int const raw );
    private:
        int _rawValue;
        static const int _fractionalBits = 8;
};
