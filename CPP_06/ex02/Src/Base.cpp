#include "../Inc/Base.hpp"
#include "../Inc/A.hpp"
#include "../Inc/B.hpp"
#include "../Inc/C.hpp"

Base::~Base() {}

Base* generate() {
    int i = std::rand() % 3;

    switch (i) {
        case 0: return new A();
        case 1: return new B();
        case 2: return new C();
        default: return NULL;
    }
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p))
        std::cout << "A\n";
    else if (dynamic_cast<B*>(p))
        std::cout << "B\n";
    else if (dynamic_cast<C*>(p))
        std::cout << "C\n";
}

void identify(Base& p) {
    identify(&p);
}
