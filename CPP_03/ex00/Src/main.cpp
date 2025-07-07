#include "../Inc/ClapTrap.hpp"

int main(void) {
    ClapTrap a("Alpha");
    ClapTrap b("Beta");

    a.attack("Beta");
    b.takeDamage(a.getAttackDamage());

    b.attack("Alpha");
    a.takeDamage(b.getAttackDamage());

    a.beRepaired(5);
    b.beRepaired(2);

    return 0;
}
