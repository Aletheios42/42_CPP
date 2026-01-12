#include "../Inc/Animal.hpp"

Animal::Animal() : _type("Default") {
    std::cout << "Constructor por defecto Animal called" << std::endl;
}

Animal::Animal(const std::string& type) : _type(type) {
    std::cout << "Constructor por de copia Animal called" << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
    if (this != &other) {
        _type = other._type;
    }
    return *this;
}

Animal::~Animal() {
    std::cout << "Destructor Animal called" << std::endl;
}

std::string Animal::getType() const {
    return _type;
}

void	Animal::setType(const std::string &type)
{
	this->_type = type;
}

void Animal::makeSound() const {
    std::cout << "*generic animal noise*" << std::endl;
}
