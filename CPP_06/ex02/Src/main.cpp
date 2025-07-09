#include "../Inc/Base.hpp"
#include "../Inc/A.hpp"
#include "../Inc/B.hpp"
#include "../Inc/C.hpp"
#include <iostream>
#include <cstdlib>

int main() {

    std::srand(std::time(NULL));

    for (int i = 0; i < 10; ++i) {
        Base* obj = generate();

        std::cout << "identify(Base*): ";
        identify(obj);

        std::cout << "identify(Base&): ";
        identify(*obj);

        delete obj;
        std::cout << "----\n";
    }
    return 0;
}
