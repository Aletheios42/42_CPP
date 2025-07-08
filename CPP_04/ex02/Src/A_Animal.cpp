#include "../Inc/A_Animal.hpp"

A_Animal::A_Animal() : _type("Default") {
    std::cout << "Constructor por defecto A_Animal called" << std::endl;
}

A_Animal::A_Animal(const std::string& type) : _type(type) {
    std::cout << "Constructor por de copia A_Animal called" << std::endl;
}

A_Animal& A_Animal::operator=(const A_Animal& other) {
    if (this != &other) {
        _type = other._type;
    }
    return *this;
}

A_Animal::~A_Animal() {
    std::cout << "Destructor A_Animal called" << std::endl;
}

std::string A_Animal::getType() const {
    return _type;
}

void A_Animal::makeSound() const {
    std::cout << "*generic animal noise*" << std::endl;
}
