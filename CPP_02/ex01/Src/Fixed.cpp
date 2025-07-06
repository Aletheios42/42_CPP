#include "../Inc/Fixed.hpp"

const int Fixed::_fractionalBits = 8;

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

// ADD
float Fixed::toFloat(void) const {
    float fl = (float)_rawValue / (1 << _fractionalBits);
    return fl;
}

int Fixed::toInt(void) const {
    int i = _rawValue >> _fractionalBits;
    return i;
}

Fixed::Fixed(const int value) : _rawValue(value << _fractionalBits) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const float value)
    : _rawValue(static_cast<int>(roundf(value * (1 << _fractionalBits)))) {
    std::cout << "Float constructor called" << std::endl;
}

std::ostream    &operator<<(std::ostream &new_out, Fixed const &fixed)
{
    new_out << fixed.toFloat();
    return (new_out);
}
