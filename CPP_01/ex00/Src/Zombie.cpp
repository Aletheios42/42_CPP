#include "../Inc/Zombie.hpp"

Zombie::Zombie(void) :name("Default") {
    std::cout << "Zombie has been created with name: "
        << name << std::endl;
}

Zombie::Zombie(std::string name) :name(name) {
    std::cout << "Zombie has been created with name: "
        << name <<std::endl;
}

Zombie::~Zombie() {
    std::cout << "Zombie with name " << name << " has been destroyed" << std::endl;
}

void Zombie::announce(void) {
    std::cout << name << ": BraiiiiiiinnnzzzZ..."
        << std::endl;
}
