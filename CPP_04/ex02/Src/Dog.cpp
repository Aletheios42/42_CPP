#include "../Inc/Dog.hpp"

Dog::Dog() : A_Animal("Dog") {
    std::cout << "Constructor por defecto Dog called" << std::endl;
    _brain = new Brain();
}

Dog::Dog(const std::string& type) : A_Animal(type) {
    std::cout << "Constructor por de copia Dog called" << std::endl;
    _brain = new Brain();
}

Dog::Dog(const Dog& other) : A_Animal(other) {
    std::cout << "Constructor por copia Dog called" << std::endl;
    _brain = new Brain(*other._brain);  // copia profunda
}

Dog& Dog::operator=(const Dog& other) {
    if (this != &other) {
        A_Animal::operator=(other);  // asegura copia correcta del base
        if (_brain)
            delete _brain;
        _brain = new Brain(*other._brain); // copia profunda
    }
    return *this;
}

Dog::~Dog() {
    std::cout << "Destructor Dog called" << std::endl;
    delete _brain;
}

void Dog::makeSound() const {
    std::cout << "Woof!" << std::endl;
}
