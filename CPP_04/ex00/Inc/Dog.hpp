#pragma once

#include "../Inc/Animal.hpp"
#include <iostream>


class Dog : public Animal {

    protected:
    public:
        Dog();
        Dog(const std::string& type);
        Dog& operator=(const Dog& other);
        ~Dog();

        void makeSound() const;
};
