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

PmergeMe::PmergeMe(char* nbrs) {
    parse_numbers(nbrs, _vector);
    _deque = std::deque<int>(_vector.begin(), _vector.end());
}

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

void PmergeMe::parse_numbers(char* nbrs, std::deque<int>& out) {
    out.clear();
    std::istringstream iss(nbrs);
    int num;
    while (iss >> num) {
        out.push_back(num);
    }
}

void PmergeMe::benchmark(const std::string& container_name) {
    std::clock_t start;
    double duration;

    if (container_name == "std::vector") {
        start = std::clock();
        _vector = ford_johnson_sort(_vector);
        duration = 1e6 * (std::clock() - start) / static_cast<double>(CLOCKS_PER_SEC);
        std::cout << "Time to process a range of " << _vector.size()
                  << " elements with std::vector : "
                  << std::fixed << std::setprecision(5) << duration << " us" << std::endl;
    } else if (container_name == "std::deque") {
        start = std::clock();
        _deque = ford_johnson_sort(_deque);
        duration = 1e6 * (std::clock() - start) / static_cast<double>(CLOCKS_PER_SEC);
        std::cout << "Time to process a range of " << _deque.size()
                  << " elements with std::deque : "
                  << std::fixed << std::setprecision(5) << duration << " us" << std::endl;
    }
}

std::vector<int> PmergeMe::ford_johnson_sort(const std::vector<int>& input) {
    if (input.size() <= 1) return input;

    std::vector<int> x, y;
    pair_and_sort(input, x, y);

    recursive_sort_y(y);

    bool has_leftover = input.size() % 2 != 0;
    int leftover = has_leftover ? input.back() : 0;

    std::vector<size_t> order = generate_jacobsthal_indices(x.size());
    for (size_t i = 0; i < order.size(); ++i) {
        if (order[i] < x.size()) {
            binary_insert(y, x[order[i]]);
        }
    }

    if (has_leftover) {
        binary_insert(y, leftover);
    }

    return y;
}

std::deque<int> PmergeMe::ford_johnson_sort(const std::deque<int>& input) {
    if (input.size() <= 1) return input;

    std::deque<int> x, y;
    pair_and_sort(input, x, y);

    recursive_sort_y(y);

    bool has_leftover = input.size() % 2 != 0;
    int leftover = has_leftover ? input.back() : 0;

    std::vector<size_t> order = generate_jacobsthal_indices(x.size());
    for (size_t i = 0; i < order.size(); ++i) {
        if (order[i] < x.size()) {
            binary_insert(y, x[order[i]]);
        }
    }

    if (has_leftover) {
        binary_insert(y, leftover);
    }

    return y;
}

void PmergeMe::binary_insert(std::vector<int>& sorted, int value) {
    int low = 0, high = (int)sorted.size();
    while (low < high) {
        int mid = (low + high) / 2;
        if (value < sorted[mid])
            high = mid;
        else
            low = mid + 1;
    }
    sorted.insert(sorted.begin() + low, value);
}

void PmergeMe::binary_insert(std::deque<int>& sorted, int value) {
    int low = 0, high = (int)sorted.size();
    while (low < high) {
        int mid = (low + high) / 2;
        if (value < sorted[mid])
            high = mid;
        else
            low = mid + 1;
    }
    sorted.insert(sorted.begin() + low, value);
}

void PmergeMe::recursive_sort_y(std::vector<int>& y) {
    if (y.size() <= 1) return;

    std::vector<int> x, y_rec;
    pair_and_sort(y, x, y_rec);
    recursive_sort_y(y_rec);

    std::vector<size_t> order = generate_jacobsthal_indices(x.size());
    for (size_t k = 0; k < order.size(); ++k)
        binary_insert(y_rec, x[order[k]]);

    y = y_rec;
}

void PmergeMe::recursive_sort_y(std::deque<int>& y) {
    if (y.size() <= 1) return;

    std::deque<int> x, y_rec;
    pair_and_sort(y, x, y_rec);
    recursive_sort_y(y_rec);

    std::vector<size_t> order = generate_jacobsthal_indices(x.size());
    for (size_t k = 0; k < order.size(); ++k)
        binary_insert(y_rec, x[order[k]]);

    y = y_rec;
}

void PmergeMe::pair_and_sort(const std::vector<int>& input, std::vector<int>& x, std::vector<int>& y) {
    x.clear();
    y.clear();
    for (size_t i = 0; i + 1 < input.size(); i += 2) {
        if (input[i] < input[i+1]) {
            x.push_back(input[i]);
            y.push_back(input[i+1]);
        } else {
            x.push_back(input[i+1]);
            y.push_back(input[i]);
        }
    }
}

void PmergeMe::pair_and_sort(const std::deque<int>& input, std::deque<int>& x, std::deque<int>& y) {
    x.clear();
    y.clear();
    for (size_t i = 0; i + 1 < input.size(); i += 2) {
        if (input[i] < input[i+1]) {
            x.push_back(input[i]);
            y.push_back(input[i+1]);
        } else {
            x.push_back(input[i+1]);
            y.push_back(input[i]);
        }
    }
}

std::vector<size_t> PmergeMe::generate_jacobsthal_indices(size_t n) {
    std::vector<size_t> indices;
    if (n == 0) return indices;

    std::vector<size_t> jacob;
    jacob.push_back(0);
    jacob.push_back(1);

    while (true) {
        size_t next = jacob.back() + 2 * jacob[jacob.size() - 2];
        if (next >= n) break;
        jacob.push_back(next);
    }

    std::vector<char> inserted(n, 0);

    for (int i = static_cast<int>(jacob.size()) - 1; i >= 0; --i) {
        size_t idx = jacob[i];
        if (idx >= n) {
            continue;
        }
        if (!inserted[idx]) {
            indices.push_back(idx);
            inserted[idx] = 1;
        }
    }

    for (size_t i = 0; i < n; ++i) {
        if (!inserted[i]) indices.push_back(i);
    }

    return indices;
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
        if (token == "0")
            return false;
    }
    return true;
}

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
