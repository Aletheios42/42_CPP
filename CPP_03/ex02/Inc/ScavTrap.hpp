#pragma once
#include <iostream>
#include <string>

#include "../Inc/ClapTrap.hpp"

class ScavTrap : public ClapTrap {
    private:

    public:
        ScavTrap();
        ScavTrap(const std::string& name);
        ScavTrap(const ScavTrap& other);
        ScavTrap& operator=(const ScavTrap& rhs);
        ~ScavTrap();

        void attack(const std::string& target);
        void guardGate();
};
