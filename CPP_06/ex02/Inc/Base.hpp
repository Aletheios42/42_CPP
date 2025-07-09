#pragma once

#include <iostream>

#include <cstdlib>   // para srand, rand
#include <ctime>     // para time
#include <iostream>  // para std::cout
#include <exception> // para std::bad_cast

class Base {
public:
    virtual ~Base(); // ← virtual
};

Base* generate();
void identify(Base* p);
void identify(Base& p);
