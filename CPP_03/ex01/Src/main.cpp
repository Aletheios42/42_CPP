#include "../Inc/ClapTrap.hpp"
#include "../Inc/ScavTrap.hpp"

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

    std::cout << "\n--- SCAVTRAP TEST ---\n" << std::endl;

    ScavTrap s("Sentinel");

    s.attack("Intruder");
    s.takeDamage(4);
    s.beRepaired(3);
    s.guardGate();

    return 0;
}

