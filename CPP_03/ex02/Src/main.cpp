#include "../Inc/ClapTrap.hpp"
#include "../Inc/FragTrap.hpp"

int main(void) {
    std::cout << "\n--- CLAPTRAP TEST ---\n" << std::endl;
    ClapTrap a("Alpha");
    ClapTrap b("Beta");

    a.attack("Beta");
    b.takeDamage(a.getAttackDamage());

    b.attack("Alpha");
    a.takeDamage(b.getAttackDamage());

    a.beRepaired(5);
    b.beRepaired(2);

    std::cout << "\n--- FRAGTRAP TEST ---\n" << std::endl;

    FragTrap f("Fragger");

    f.attack("Target");
    f.takeDamage(20);
    f.beRepaired(15);
    f.highFivesGuys();

    return 0;
}

