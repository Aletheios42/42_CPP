#include "../Inc/Zombie.hpp"

Zombie* newZombie(std::string name) {
    return new Zombie(name);
}

void randomChump(std::string name) {
    Zombie z1(name);
    z1.announce();
}

Zombie* zombieHorde( int N, std::string name ) {
    if (N < 0)
        return NULL;

    Zombie *horde = new Zombie[N];
    for (int i = 0; i < N; i++) {
        horde[i] = Zombie(name);
    }

    return horde;
}
