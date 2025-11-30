#include "../Inc/Zombie.hpp"

int main(void) {

    Zombie z1;
    Zombie z2("Raul");
    Zombie* z3 = newZombie("Jose");


    z1.announce();
    z2.announce();

    delete(z3);
    return 0;
}
