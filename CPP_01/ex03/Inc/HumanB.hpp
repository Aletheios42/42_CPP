#pragma once

#include <iostream>
#include "Weapon.hpp"

class HumanB {
    private:
        Weapon _weapon;
        std::string _name;

    public:
        HumanB();
        HumanB(std::string name);
        ~HumanB();

        void attack();
        void setWeapon(Weapon);
};
