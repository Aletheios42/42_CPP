#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <algorithm>
#include <ctime>
#include <sstream>
#include <climits>
#include <cstdlib>
#include <set>

class PmergeMe {
public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();

    PmergeMe(int argc, char** argv);

    void execute();

private:
    std::vector<int> _vectorArg;
    std::deque<int>  _dequeArg;

    void parseArgs(int argc, char** argv);

    void sortVector(std::vector<int>& arr);
    void sortDeque(std::deque<int>& arr);

    template <typename T>
    void binaryInsert(T& mainChain, int val, int limitIndex);
    
    int  getJacobsthal(int n);
    void generateJacobsthalSequence(std::vector<int>& seq, int n);
};

#endif