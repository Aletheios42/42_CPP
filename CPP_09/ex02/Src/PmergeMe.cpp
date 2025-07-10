#include "../Inc/PmergeMe.hpp"

#include <iomanip>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <cctype>
#include <stdexcept>

PmergeMe::PmergeMe()
    : _vector(), _deque()
{}

PmergeMe::PmergeMe(const PmergeMe& other)
    : _vector(other._vector), _deque(other._deque)
{}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {
        _vector = other._vector;
        _deque = other._deque;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}


void PmergeMe::parse_numbers(char* nbrs, std::vector<int>& out) {
    out.clear();
    std::istringstream iss(nbrs);
    int num;
    while (iss >> num) {
        out.push_back(num);
    }
}

void PmergeMe::sort_vec(char* nbrs) {
    parse_numbers(nbrs, _vector);
    std::sort(_vector.begin(), _vector.end());
}

void PmergeMe::sort_deque(char* nbrs) {
    std::vector<int> temp_vec;
    parse_numbers(nbrs, temp_vec);
    _deque.assign(temp_vec.begin(), temp_vec.end());
    std::sort(_deque.begin(), _deque.end());
}


void PmergeMe::benchmark(MemberFunc func, char* nbrs, const char* container_name) {
    std::clock_t start = std::clock();
    (this->*func)(nbrs);
    std::clock_t end = std::clock();

    double elapsed_us = (static_cast<double>(end - start) / CLOCKS_PER_SEC) * 1e6;

    // Obtener tamaño correcto para imprimir (vector o deque)
    size_t count = 0;
    if (std::string(container_name) == "std::vector")
        count = _vector.size();
    else if (std::string(container_name) == "std::deque")
        count = _deque.size();

    std::cout << "Time to process a range of " << count << " elements with " << container_name
              << " : " << std::fixed << std::setprecision(5) << elapsed_us << " us" << std::endl;
}

bool PmergeMe::validate_arguments(char* input) {
    std::istringstream iss(input);
    std::string token;
    while (iss >> token) {
        if (token.empty())
            return false;
        for (size_t i = 0; i < token.size(); ++i) {
            if (!std::isdigit(token[i]))
                return false;
        }
        if (token == "0")  // 0 no es positivo
            return false;
    }
    return true;
}

// En PmergeMe.cpp
std::ostream& operator<<(std::ostream& os, const std::vector<int>& vec) {
    for (size_t i = 0; i < vec.size(); ++i)
        os << vec[i] << (i + 1 < vec.size() ? " " : "");
    return os;
}

std::ostream& operator<<(std::ostream& os, const std::deque<int>& deq) {
    for (size_t i = 0; i < deq.size(); ++i)
        os << deq[i] << (i + 1 < deq.size() ? " " : "");
    return os;
}

std::vector<int>& PmergeMe::get_vector() { return _vector; }
std::deque<int>& PmergeMe::get_deque() { return _deque; }
