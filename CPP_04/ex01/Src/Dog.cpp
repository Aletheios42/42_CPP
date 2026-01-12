#include "../Inc/Dog.hpp"

Dog::Dog() : Animal("Dog") {
    std::cout << "Constructor por defecto Dog called" << std::endl;
    this->_brain = new Brain();
}

Dog::Dog(const std::string& type) : Animal(type) {
    std::cout << "Constructor por de copia Dog called" << std::endl;
}

Dog::Dog(const Dog& other) :	Animal(other),
								_brain(new Brain(*other._brain))
{
	std::cout <<  "Dog Copy Constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    if (this != &other) {
        _type = other._type;
        _brain = other._brain;

    }
    return *this;
}

Dog::~Dog() {
    std::cout << "Destructor Dog called" << std::endl;
    delete(this->_brain);
}

void Dog::makeSound() const {
    std::cout << "Woof!" << std::endl;
}

void	Dog::setBrain(const Brain& brain)
{
	*this->_brain = brain;
}

Brain& Dog::getBrain() const
{
	return(*this->_brain);
}