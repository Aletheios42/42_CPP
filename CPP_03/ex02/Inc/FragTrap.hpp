#pragma once
#include <iostream>
#include <string>
#include "../Inc/ClapTrap.hpp"

class FragTrap : public ClapTrap{
    private:

    public:
        FragTrap();
        FragTrap(const std::string& name);
        FragTrap(const FragTrap& other);
        FragTrap& operator=(const FragTrap& rhs);
        ~FragTrap();

        void highFivesGuys();
};

