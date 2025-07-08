#pragma once

#include <iostream>

class Animal {

    protected:
        std::string _type;
    public:
        Animal();
        Animal(const std::string& type);
        Animal& operator=(const Animal& other);
        ~Animal();


        std::string getType() const;
        virtual void makeSound() const;
};
