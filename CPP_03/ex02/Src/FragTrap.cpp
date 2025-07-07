#include "../Inc/FragTrap.hpp"

FragTrap::FragTrap()
    : ClapTrap("FragTrap") {
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap default constructor called\n";
}

FragTrap::FragTrap(const std::string& name)
    : ClapTrap(name) {
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap named constructor called\n";
}

FragTrap::FragTrap(const FragTrap& other)
    : ClapTrap(other) {
    std::cout << "FragTrap copy constructor called\n";
}

FragTrap& FragTrap::operator=(const FragTrap& rhs) {
    if (this != &rhs) {
        ClapTrap::operator=(rhs);
    }
    std::cout << "FragTrap copy assignment operator called\n";
    return *this;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap destructor called\n";
}

void FragTrap::highFivesGuys() {
    std::cout << "FragTrap " << _name << " requests a high five!\n";
}

