#include "../Inc/Dog.hpp"

Dog::Dog() : Animal("Dog") {
    std::cout << "Constructor por defecto Dog called" << std::endl;
}

Dog::Dog(const std::string& type) : Animal(type) {
    std::cout << "Constructor por de copia Dog called" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    if (this != &other) {
        _type = other._type;
    }
    return *this;
}

Dog::~Dog() {
    std::cout << "Destructor Dog called" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "Woof!" << std::endl;
}
