#include "../Inc/Cat.hpp"

Cat::Cat() : Animal("Cat") {
    std::cout << "Constructor por defecto Cat called" << std::endl;
    this->_brain = new Brain();
}

Cat::Cat(const std::string& type) : Animal(type) {
    std::cout << "Constructor por de copia Cat called" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    if (this != &other) {
        _type = other._type;
        _brain = other._brain;

    }
    return *this;
}

Cat::~Cat() {
    std::cout << "Destructor Cat called" << std::endl;
    delete(this->_brain);

}

void Cat::makeSound() const {
    std::cout << "Miauu!" << std::endl;
}

void	Cat::setBrain(const Brain& brain)
{
	*this->_brain = brain;
}

Brain& Cat::getBrain() const
{
	return(*this->_brain);
}