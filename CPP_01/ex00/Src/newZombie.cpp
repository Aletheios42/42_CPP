#include "../Inc/Zombie.hpp"

Zombie* newZombie(std::string name) {
    return new Zombie(name);
}

void randomChump(std::string name) {
    Zombie z1(name);
    z1.announce();
}

