#include "../Inc/ClapTrap.hpp"
#include "../Inc/FragTrap.hpp"
#include "../Inc/ScavTrap.hpp"
#include "../Inc/DiamondTrap.hpp"
#include <iostream>

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

    std::cout << "\n--- DIAMONDTRAP TEST ---\n" << std::endl;

    DiamondTrap d("Diamondy");

    d.attack("Enemy");
    d.takeDamage(30);
    d.beRepaired(20);
    d.whoAmI();

    return 0;
}

