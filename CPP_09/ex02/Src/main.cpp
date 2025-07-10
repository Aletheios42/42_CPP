#include "../Inc/PmergeMe.hpp"
#include <iostream>
#include <stdexcept>
#include <cstring>   // para strlen
#include <iostream>

#include <ctime>
#include <iomanip> // para std::fixed y std::setprecision

int main(int argc, char** argv) {
    if (argc < 2 || !*argv[1] || std::strlen(argv[1]) == 0) {
        std::cerr << "Error: se requiere una cadena de números separados por espacios como argumento.\n";
        return 1;
    }

    PmergeMe pm;

    if (!pm.validate_arguments(argv[1])) {
        std::cerr << "Error: argumentos inválidos. Deben ser enteros positivos.\n";
        return 1;
    }

    pm.parse_numbers(argv[1], pm.get_vector());
    pm.get_deque() = std::deque<int>(pm.get_vector().begin(), pm.get_vector().end());

    std::cout << "Before: " << pm.get_vector() << std::endl;

    pm.benchmark(&PmergeMe::sort_vec, argv[1], "std::vector");
    std::cout << "After:  " << pm.get_vector() << std::endl;

    pm.benchmark(&PmergeMe::sort_deque, argv[1], "std::deque");

    return 0;
}
