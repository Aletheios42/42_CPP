#include "../Inc/ClapTrap.hpp"

ClapTrap::ClapTrap()
    : _name("ClapTrap"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "Default constructor called\n";
}

ClapTrap::ClapTrap(const std::string& name)
    : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "Constructor with _name called for " << _name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
    : _name(other._name), _hitPoints(other._hitPoints),
      _energyPoints(other._energyPoints), _attackDamage(other._attackDamage) {
    std::cout << "Copy constructor called\n";
}

ClapTrap& ClapTrap::operator=(const ClapTrap& rhs) {
    if (this != &rhs) {
        _name = rhs._name;
        _hitPoints = rhs._hitPoints;
        _energyPoints = rhs._energyPoints;
        _attackDamage = rhs._attackDamage;
    }
    std::cout << "Copy assignment operator called\n";
    return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << "Destructor called\n";
}

void ClapTrap::attack(const std::string& target) {
    if (_hitPoints > 0 && _energyPoints > 0) {
        _energyPoints--;
        std::cout << "ClapTrap " << _name << " attacks " << target
                  << ", causing " << _attackDamage << " points of damage!" << std::endl;
    } else {
        std::cout << "ClapTrap " << _name << " can't attack " << target
                  << ". Not enough energy or hit points." << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (_hitPoints <= 0) {
        std::cout << "ClapTrap " << _name << " is already dead." << std::endl;
        return;
    }

    _hitPoints -= amount;
    if (_hitPoints <= 0) {
        _hitPoints = 0;
        std::cout << "ClapTrap " << _name << " took " << amount
                  << " damage and died!" << std::endl;
    } else {
        std::cout << "ClapTrap " << _name << " took " << amount
                  << " damage, remaining HP: " << _hitPoints << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (_hitPoints > 0 && _energyPoints > 0) {
        _energyPoints--;
        _hitPoints += amount;
        std::cout << "ClapTrap " << _name << " repairs itself for " << amount
                  << " hit points, total HP: " << _hitPoints << std::endl;
    } else {
        std::cout << "ClapTrap " << _name << " can't repair. Not enough energy or is dead." << std::endl;
    }
}

int ClapTrap::getAttackDamage() const {
    return _attackDamage;
}
