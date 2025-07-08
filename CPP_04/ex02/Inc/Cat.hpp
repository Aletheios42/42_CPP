#pragma once

#include "../Inc/A_Animal.hpp"
#include "../Inc/Brain.hpp"
#include <iostream>

class Cat : public A_Animal, public Brain {

    private:
        Brain *_brain;
    public:
        Cat();
        Cat(const std::string& type);
        Cat(const Cat& other);
        Cat& operator=(const Cat& other);
        ~Cat();

        void makeSound() const;
};
