#pragma once

#include <iostream>

class WrongAnimal {

    protected:
        std::string _type;
    public:
        WrongAnimal();
        WrongAnimal(const std::string& type);
        WrongAnimal& operator=(const WrongAnimal& other);
        virtual ~WrongAnimal();


		std::string const &getType() const;
		void	setType(const std::string &type);
		
		virtual void	makeSound() const;
	
};
