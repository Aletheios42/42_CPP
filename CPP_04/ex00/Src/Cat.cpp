#include "../Inc/Cat.hpp"

Cat::Cat() : Animal("Cat") {
    std::cout << "Constructor por defecto Cat called" << std::endl;
}

Cat::Cat(const std::string& type) : Animal(type) {
    std::cout << "Constructor por de copia Cat called" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    if (this != &other) {
        _type = other._type;
    }
    return *this;
}

Cat::~Cat() {
    std::cout << "Destructor Cat called" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "Miauu!" << std::endl;
}
