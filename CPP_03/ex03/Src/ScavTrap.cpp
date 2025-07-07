#include "../Inc/ScavTrap.hpp"

ScavTrap::ScavTrap()
    : ClapTrap("ScavTrap") {
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap default constructor called\n";
}

ScavTrap::ScavTrap(const std::string& name)
    : ClapTrap(name) {
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap named constructor called\n";
}

ScavTrap::ScavTrap(const ScavTrap& other)
    : ClapTrap(other) {
    std::cout << "ScavTrap copy constructor called\n";
}

ScavTrap& ScavTrap::operator=(const ScavTrap& rhs) {
    if (this != &rhs)
        ClapTrap::operator=(rhs);
    std::cout << "ScavTrap copy assignment operator called\n";
    return *this;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap destructor called\n";
}

void ScavTrap::attack(const std::string& target) {
    if (_hitPoints > 0 && _energyPoints > 0) {
        _energyPoints--;
        std::cout << "ScavTrap " << _name << " attacks " << target
                  << ", causing " << _attackDamage << " points of damage!" << std::endl;
    } else {
        std::cout << "ScavTrap " << _name << " can't attack " << target
                  << ". Not enough energy or hit points." << std::endl;
    }
}
void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << _name << " has entered Gate Keeper mode.\n";
}
