#include "../Inc/PmergeMe.hpp"
#include <iostream>
#include <stdexcept>
#include <cstring>   // para strlen
#include <iostream>

#include <ctime>
#include <iomanip> // para std::fixed y std::setprecision

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    try {
        PmergeMe pm(argv[1]);  // Salta argv[0]

        std::cout << "vector: Before: " << pm.get_vector() << std::endl;
        std::cout << "deque: Before: " << pm.get_deque() << std::endl;

        pm.benchmark("std::vector");
        pm.benchmark("std::deque");

        std::cout << "vector: After: " << pm.get_vector() << std::endl;
        std::cout << "deque: After: " << pm.get_deque() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    return 0;
}
