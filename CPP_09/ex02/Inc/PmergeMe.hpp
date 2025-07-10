#ifndef PmergeMe_HPP
#define PmergeMe_HPP

#include <stack>
#include <string>
#include <vector>
#include <deque>
#include <ctime>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <algorithm>  // std::sort
#include <cstring>


class PmergeMe {
private:
    std::vector<int> _vector;
    std::deque<int>  _deque;

public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();

    typedef void (PmergeMe::*MemberFunc)(char*);

    void benchmark(MemberFunc func, char* nbrs, const char* container_name);

    void sort_vec(char* nbrs);
    void sort_deque(char* nbrs);

    void parse_numbers(char* nbrs, std::vector<int>& out);

    bool validate_arguments(char* input);

    //Getters
    std::vector<int>& get_vector();
    std::deque<int>& get_deque();
};

// En PmergeMe.hpp (fuera de la clase)
std::ostream& operator<<(std::ostream& os, const std::vector<int>& vec);
std::ostream& operator<<(std::ostream& os, const std::deque<int>& deq);

#endif // PmergeMe_HPP

