#pragma once

#include <iostream>

class Weapon {
    private:
        std::string _type;
    public:
        const std::string& getType();
        void setType(const std::string&);
        Weapon();
        Weapon(std::string type);
        ~Weapon();
};
