#pragma once

#include "../Inc/ICharacter.hpp"

#include <iostream>
#include <string>

class Character : public ICharacter {
    protected:
        std::string _name;
        AMateria *_slots[4];
    public:
        Character(); 
        Character(std::string name); 
        Character(const Character& other); 
        Character& operator=(const Character& Character);
        ~Character(); 

        std::string const & getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
};
