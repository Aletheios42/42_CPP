#include "../Inc/Fixed.hpp"

Fixed::Fixed() {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;
    this->_rawValue = other._rawValue;
}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->_rawValue = other._rawValue;
    }
    return *this;
}


int Fixed::getRawBits( void ) const {
    std::cout << "getRawBits member function called" << std::endl;
    return _rawValue;}

void Fixed::setRawBits( int const raw ) {_rawValue = raw;}
