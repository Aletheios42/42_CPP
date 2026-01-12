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

std::string const	&WrongAnimal::getType() const
{
	return(this->_type);
}

void	WrongAnimal::setType(const std::string &type)
{
	this->_type = type;
}

void	WrongAnimal::makeSound() const
{
	std::cout << "**Wrong default sound**" << std::endl;
}