#include "../Inc/Fixed.hpp"

const int Fixed::_fractionalBits = 8;

Fixed::Fixed() :_rawValue(0) {
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

float Fixed::toFloat(void) const {
    float fl = (float)_rawValue / (1 << _fractionalBits);
    return fl;
}

int Fixed::toInt(void) const {
    int i = _rawValue >> _fractionalBits;
    return i;
}

Fixed::Fixed(const int value) : _rawValue(value << _fractionalBits) {
    std::cout << "Int constructor called" << std::endl;
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

// ADD
Fixed Fixed::operator+(Fixed const &fixed) {
    Fixed result;
    result.setRawBits(this->_rawValue + fixed._rawValue);
    return result;
}

Fixed Fixed::operator-(Fixed const &fixed) {
    Fixed result;
    result.setRawBits(this->_rawValue - fixed._rawValue);
    return result;
}

Fixed   Fixed::operator*(Fixed const &fixed)
{
    return (Fixed((_rawValue / (float)(1 << _fractionalBits)) *
                (fixed._rawValue/ (float)(1 << _fractionalBits))));
}

Fixed Fixed::operator/(Fixed const &fixed) {
    Fixed result;
    int64_t dividend = (_rawValue) << _fractionalBits;
    int64_t divisor = (fixed.getRawBits());
    result.setRawBits((int)(dividend / divisor));
    return result;
}

bool Fixed::operator==(Fixed const &fixed)  const {
    return this->_rawValue == fixed._rawValue;
}
bool Fixed::operator!=(Fixed const &fixed)  const {
    return this->_rawValue != fixed._rawValue;
}
bool Fixed::operator<(Fixed const &fixed)  const {
    return this->_rawValue < fixed._rawValue;
}
bool Fixed::operator<=(Fixed const &fixed)  const {
    return this->_rawValue <= fixed._rawValue;
}
bool Fixed::operator>(Fixed const &fixed)  const {
    return this->_rawValue > fixed._rawValue;
}
bool Fixed::operator>=(Fixed const &fixed)  const {
    return this->_rawValue >= fixed._rawValue;
}

Fixed& Fixed::operator++() {
    ++_rawValue;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed tmp = *this;
    ++_rawValue;
    return tmp;
}

Fixed& Fixed::operator--() {
    --_rawValue;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed tmp = *this;
    --_rawValue;
    return tmp;
}

Fixed &Fixed::min(Fixed &f1, Fixed &f2) {
    return (f1 < f2 ? f1 : f2);
}

const Fixed &Fixed::min(const Fixed &f1, const Fixed &f2) {
    return (f1 < f2 ? f1 : f2);
}

Fixed &Fixed::max(Fixed &f1, Fixed &f2) {
    return (f1 > f2 ? f1 : f2);
}

const Fixed &Fixed::max(const Fixed &f1, const Fixed &f2) {
    return (f1 > f2 ? f1 : f2);
}
