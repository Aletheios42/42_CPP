#pragma once

#include "../Inc/ScavTrap.hpp"
#include "../Inc/FragTrap.hpp"
#include "../Inc/ClapTrap.hpp"

#include <iostream>

class DiamondTrap : public FragTrap, public ScavTrap {
private:
	std::string _name;

public:
	DiamondTrap(const std::string& name);
	DiamondTrap(const DiamondTrap& other);
	DiamondTrap& operator=(const DiamondTrap& other);
	~DiamondTrap();

	void whoAmI();
	void attack(const std::string& target);
};
