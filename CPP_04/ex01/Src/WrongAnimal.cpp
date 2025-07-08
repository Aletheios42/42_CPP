#include "../Inc/WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("Default") {
    std::cout << "Constructor por defecto WrongAnimal called" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string& type) : _type(type) {
    std::cout << "Constructor por de copia WrongAnimal called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
    if (this != &other) {
        _type = other._type;
    }
    return *this;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "Destructor WrongAnimal called" << std::endl;
}

std::string WrongAnimal::getType() const {
    return _type;
}

void WrongAnimal::makeSound() const {
    std::cout << "*generic WrongAnimal noise*" << std::endl;
}
