#pragma once

#include <iostream>
class A_Animal {

    protected:
        std::string _type;
    public:
        A_Animal();
        A_Animal(const std::string& type);
        A_Animal& operator=(const A_Animal& other);
        ~A_Animal();


        std::string getType() const;
        virtual void makeSound(void) const = 0;
};
