#pragma once

#include <iostream>
#include <iomanip>

class Zombie {
    private:
        std::string _name;
    public:
        Zombie();
        Zombie(std::string name);
        void announce(void);
        ~Zombie();
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);
