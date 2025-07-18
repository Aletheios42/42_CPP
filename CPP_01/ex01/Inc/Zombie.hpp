#pragma once

#include <iostream>
#include <iomanip>

class Zombie {
    private:
        std::string name;
    public:
        Zombie();
        Zombie(std::string _name);
        void announce(void);
        ~Zombie();
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);
Zombie* zombieHorde( int N, std::string name );
