#pragma once

#include "../Inc/Animal.hpp"
#include "../Inc/Brain.hpp"
#include <iostream>

class Cat : public Animal, public Brain {

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
