#include "../Inc/Weapon.hpp"

Weapon::Weapon() {
    type = "Default";
    std::cout << "Arma creada de tipo: " << type << std::endl;
}

Weapon::Weapon(std::string _type) : type(_type) {
    std::cout << "Arma creada de tipo: " << _type << std::endl;
}

Weapon::~Weapon() {
    std::cout << "Arma destruida de tipo: " << type << std::endl;
}

const std::string& Weapon::getType() {return type;}
void Weapon::setType(const std::string& _type) {type = _type;}

