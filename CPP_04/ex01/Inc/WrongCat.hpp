#pragma once

#include <iostream>
#include "../Inc/WrongAnimal.hpp"

class WrongCat : public WrongAnimal  {

    protected:
    public:
        WrongCat();
        WrongCat(const std::string& type);
        WrongCat& operator=(const WrongCat& other);
        ~WrongCat();

        void makeSound() const;
};
