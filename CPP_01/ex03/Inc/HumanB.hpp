#pragma once

#include <iostream>
#include "Weapon.hpp"

class HumanB {

    private:
        Weapon weapon;
        std::string name;

    public:
        HumanB();
        HumanB(std::string _name);
        ~HumanB();
        void attack();
        void setWeapon(Weapon);
};
