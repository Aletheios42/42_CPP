#pragma once

#include <iostream>
#include "Weapon.hpp"

class HumanA {

    private:
        Weapon weapon;
        std::string name;

    public:
        HumanA();
        HumanA(std::string, Weapon);
        ~HumanA();
        void attack();
};
