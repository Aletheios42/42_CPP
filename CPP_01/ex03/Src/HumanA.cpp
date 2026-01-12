#include "../Inc/HumanA.hpp"

// HumanA::HumanA():name("Default"), weapon() {
//     std::cout << "Creando humanoA default" << std::endl;
// }

HumanA::HumanA(std::string name, Weapon &weapon)
    : _weapon(weapon), _name(name) {
         std::cout << "Creando humanoA" << std::endl;
}
HumanA::~HumanA() {
    std::cout << "HumanA destruido" << std::endl;;
}

void HumanA::attack() {
    std::cout << _name << " attacks with their " 
        << _weapon.getType() << std::endl;
}
