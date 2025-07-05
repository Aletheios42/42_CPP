#include "../Inc/Weapon.hpp"

const std::string& Weapon::getType() {return type;}
void Weapon::setType(const std::string& _type) {type = _type;}

Weapon::Weapon() {
    type = "Default";
    std::cout << "Arma creada de tipo: " << type;
}

Weapon::Weapon(std::string _type) : type(_type) {
    std::cout << "Arma creada de tipo: " << _type << std::endl;
}


Weapon::~Weapon() {
    std::cout << "Arma destruida de tipo: " << type;
}

