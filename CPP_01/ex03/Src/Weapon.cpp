#include "../Inc/Weapon.hpp"

Weapon::Weapon() {
    _type = "Default";
    std::cout << "Arma creada de tipo: " << _type << std::endl;
}

Weapon::Weapon(std::string type) : _type(type) {
    std::cout << "Arma creada de tipo: " << _type << std::endl;
}

Weapon::~Weapon() {
    std::cout << "Arma destruida de tipo: " << _type << std::endl;
}

const std::string& Weapon::getType() {return _type;}
void Weapon::setType(const std::string& type) {_type = type;}

