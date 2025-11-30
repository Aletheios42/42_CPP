#pragma once

#include <iostream>
#include "Weapon.hpp"

class HumanA {

    private:
        Weapon &_weapon;
        std::string _name;

    public:
        HumanA();
        HumanA(std::string, Weapon &weapon);
        ~HumanA();
        void attack();
};
