#pragma once

#include <iostream>
#include "../Inc/Animal.hpp"

class Cat : public Animal  {

    protected:
    public:
        Cat();
        Cat(const std::string& type);
        Cat& operator=(const Cat& other);
        ~Cat();

        void makeSound() const;
};
