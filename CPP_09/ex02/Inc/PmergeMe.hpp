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
    PmergeMe(char* nbrs);
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();

    typedef void (PmergeMe::*MemberFunc)(char*);

    bool validate_arguments(char* input);
    void benchmark(const std::string& container_name);
    std::vector<size_t> generate_jacobsthal_indices(size_t n);

    // --- Declaración para std::vector ---
    void parse_numbers(char* nbrs, std::vector<int>& out);
    void pair_and_sort(const std::vector<int>& input,
                       std::vector<int>& x, std::vector<int>& y);
    void recursive_sort_y(std::vector<int>& y);
    void binary_insert(std::vector<int>& sorted, int value);
    std::vector<int> ford_johnson_sort(const std::vector<int>& input);

    // --- Declaración para std::deque ---
    void parse_numbers(char* nbrs, std::deque<int>& out);
    void pair_and_sort(const std::deque<int>& input,
                       std::deque<int>& x, std::deque<int>& y);
    void recursive_sort_y(std::deque<int>& y);
    void binary_insert(std::deque<int>& sorted, int value);
    std::deque<int> ford_johnson_sort(const std::deque<int>& input);

    //Getters
    std::vector<int>& get_vector();
    std::deque<int>& get_deque();
};

std::ostream& operator<<(std::ostream& os, const std::vector<int>& vec);
std::ostream& operator<<(std::ostream& os, const std::deque<int>& deq);

#endif // PmergeMe_HPP

