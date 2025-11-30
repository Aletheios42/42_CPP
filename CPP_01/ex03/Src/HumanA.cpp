#include "../Inc/HumanA.hpp"

// HumanA::HumanA():name("Default"), weapon() {
//     std::cout << "Creando humanoA default" << std::endl;
// }

HumanA::HumanA(std::string _name, Weapon &_weapon)
    : name(_name), weapon(_weapon) {
         std::cout << "Creando humanoA" << std::endl;
}
HumanA::~HumanA() {
    std::cout << "HumanA destruido" << std::endl;;
}

void HumanA::attack() {
    std::cout << name << " attacks with their " 
        << weapon.getType() << std::endl;
}
