#pragma once
#include <iostream>
#include <string>

class ClapTrap {
    protected:
        std::string _name;
        int _hitPoints;
        int _energyPoints;
        int _attackDamage;

    public:
        ClapTrap();                               // Default constructor
        ClapTrap(const std::string& name);
        ClapTrap(const ClapTrap& other);          // Copy constructor
        ClapTrap& operator=(const ClapTrap& rhs); // Copy assignment
        ~ClapTrap();                              // Destructor

        virtual void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

        int getAttackDamage() const;
};
