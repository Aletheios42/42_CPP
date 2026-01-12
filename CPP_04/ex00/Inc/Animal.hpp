#pragma once

#include <iostream>

class Animal {

    protected:
        std::string _type;
    public:
        Animal();
        Animal(const std::string& type);
        Animal& operator=(const Animal& other);
        virtual ~Animal();


        std::string getType() const;
        void	setType(const std::string &type);

        virtual void makeSound() const;
};
