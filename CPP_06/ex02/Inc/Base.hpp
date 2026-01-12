#pragma once

#include <iostream>

#include <cstdlib> 
#include <ctime>
#include <iostream>
#include <exception>

class Base {
public:
    virtual ~Base();
};

Base* generate();
void identify(Base* p);
void identify(Base& p);
