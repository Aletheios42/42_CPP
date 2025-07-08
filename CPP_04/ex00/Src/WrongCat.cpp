#include "../Inc/WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
    std::cout << "Constructor por defecto WrongCat called" << std::endl;
}

WrongCat::WrongCat(const std::string& type) : WrongAnimal(type) {
    std::cout << "Constructor por de copia WrongCat called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
    if (this != &other) {
        _type = other._type;
    }
    return *this;
}

WrongCat::~WrongCat() {
    std::cout << "Destructor WrongCat called" << std::endl;
}

void WrongCat::makeSound() const {
    std::cout << "Miauu!" << std::endl;
}
