#pragma once

#include "../Inc/AMateria.hpp"
#include "../Inc/ICharacter.hpp"

#include <iostream>

class Ice : public AMateria {

    public:
        Ice(); 
        Ice(const Ice& other); 
        Ice& operator=(const Ice &Ice);; 
        ~Ice(); 

        virtual AMateria* clone() const;
        void use(ICharacter& target);
};