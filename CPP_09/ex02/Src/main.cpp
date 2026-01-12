#include "../Inc/PmergeMe.hpp"
#include <iostream>

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Error: No arguments provided." << std::endl;
        return 1;
    }

    try {
        PmergeMe sorter(argc, argv);
        sorter.execute();
    } catch (const std::exception& e) {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    return 0;
}