#include "../Inc/RNP.hpp"
#include <iostream>
#include <stdexcept>

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Error: wrong number of arguments" << std::endl;
        return 1;
    }
    try {
        RPN rpn;
        if (!rpn.isValidExpression(argv[1]))
            throw std::runtime_error("Invalid expression");
        int result = rpn.execute(argv[1]);
        std::cout << result << std::endl;
    } catch(const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}

