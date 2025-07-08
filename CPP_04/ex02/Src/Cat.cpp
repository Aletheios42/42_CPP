#include "../Inc/Cat.hpp"

Cat::Cat() : A_Animal("Cat") {
    std::cout << "Constructor por defecto Cat called" << std::endl;

    _brain = new Brain();
}

Cat::Cat(const std::string& type) : A_Animal(type) {
    std::cout << "Constructor por de copia Cat called" << std::endl;

    _brain = new Brain();
}


Cat::Cat(const Cat& other) : A_Animal(other) {
    std::cout << "Constructor por copia Cat called" << std::endl;
    _brain = new Brain(*other._brain);  // copia profunda
}

Cat& Cat::operator=(const Cat& other) {
    if (this != &other) {
        _type = other._type;
        if (_brain)
            delete _brain;
        _brain = new Brain(*other._brain);
    }
    return *this;
}

Cat::~Cat() {
    std::cout << "Destructor Cat called" << std::endl;
    delete _brain;
}

void Cat::makeSound() const {
    std::cout << "Miauu!" << std::endl;
}
