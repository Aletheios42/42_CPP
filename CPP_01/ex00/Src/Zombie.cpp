#include "../Inc/Zombie.hpp"

Zombie::Zombie(void) :_name("Default") {
    std::cout << "Zombie has been created with name: "
        << _name << std::endl;
}

Zombie::Zombie(std::string _name) :_name(_name) {
    std::cout << "Zombie has been created with name: "
        << _name <<std::endl;
}

Zombie::~Zombie() {
    std::cout << "Zombie with name " << _name << " has been destroyed" << std::endl;
}

void Zombie::announce(void) {
    std::cout << _name << ": BraiiiiiiinnnzzzZ..."
        << std::endl;
}
