#include "../Inc/HumanB.hpp"

HumanB::HumanB() {
    std::cout << "HumanB creado" << std::endl;
}

HumanB::HumanB(std::string name) : _name(name) {
    std::cout << "HumanB creado "
        << _weapon.getType() << std::endl;
}

HumanB::~HumanB() {
    std::cout << "HumanB destruido" << std::endl;
}

void HumanB::attack() {
    std::cout << _name << " attacks with their " 
        << _weapon.getType() << std::endl;
}

void HumanB::setWeapon(Weapon weapon) {
    _weapon = weapon;
}
