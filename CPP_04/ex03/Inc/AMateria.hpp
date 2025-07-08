#pragma once

#include <iostream>

class ICharacter;

class AMateria {
    protected:
        std::string _type;
    public:
        AMateria();
        AMateria(std::string const & type);
        AMateria(AMateria const& materia);
        AMateria& operator=(AMateria const& other);
        virtual ~AMateria();

        std::string const & getType() const;

        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);

};
