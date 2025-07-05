#include "../Inc/HumanB.hpp"

HumanB::HumanB() {
    std::cout << "HumanB creado";
}

HumanB::HumanB(std::string _name) : name(_name) {
    std::cout << "HumanB creado"
        << weapon.getType() << std::endl;
}

HumanB::~HumanB() {
    std::cout << "HumanB destruido";
}

void HumanB::attack() {
    std::cout << name << " attacks with their " 
        << weapon.getType() << std::endl;
}

void HumanB::setWeapon(Weapon _weapon) {
    weapon = _weapon;
}
