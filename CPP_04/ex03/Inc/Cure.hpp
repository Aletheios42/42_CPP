#pragma once

#include "../Inc/AMateria.hpp"
#include "../Inc/ICharacter.hpp"

#include <iostream>

class Cure : public AMateria {

    public:
        Cure(); 
        Cure(const Cure& other); 
        Cure& operator=(const Cure& Cure);; 
        ~Cure(); 


        virtual AMateria* clone() const;
        void use(ICharacter& target);
};