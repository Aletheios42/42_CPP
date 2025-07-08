#pragma once

#include "../Inc/A_Animal.hpp"
#include "../Inc/Brain.hpp"
#include <iostream>

class Dog : public A_Animal, public Brain {

    private:
        Brain *_brain;
    public:
        Dog();
        Dog(const std::string& type);
        Dog(const Dog& other);
        Dog& operator=(const Dog& other);
        ~Dog();

        void makeSound() const;
};
