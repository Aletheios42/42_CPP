#include "../Inc/PmergeMe.hpp"
#include <iomanip>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) {
    *this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {
        _vectorArg = other._vectorArg;
        _dequeArg = other._dequeArg;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(int argc, char** argv) {
    parseArgs(argc, argv);
}

void PmergeMe::parseArgs(int argc, char** argv) {
    std::set<int> duplicates;

    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        
        for (size_t j = 0; j < arg.length(); ++j) {
            if (!isdigit(arg[j]))
                throw std::invalid_argument("Error");
        }
        
        long val = std::atol(arg.c_str());
        if (val > INT_MAX || val < 0)
            throw std::invalid_argument("Error");

        if (duplicates.find(static_cast<int>(val)) != duplicates.end())
            throw std::invalid_argument("Error");
        duplicates.insert(static_cast<int>(val));

        _vectorArg.push_back(static_cast<int>(val));
        _dequeArg.push_back(static_cast<int>(val));
    }
}

void PmergeMe::execute() {
    // 1. Mostrar estado inicial
    std::cout << "Before: ";
    for (size_t i = 0; i < _vectorArg.size(); ++i) std::cout << _vectorArg[i] << " ";
    std::cout << std::endl;

    // 2. Benchmark Vector
    std::clock_t startVec = std::clock();
    sortVector(_vectorArg);
    std::clock_t endVec = std::clock();
    double timeVec = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC * 1000000;

    // 3. Benchmark Deque
    std::clock_t startDeq = std::clock();
    sortDeque(_dequeArg);
    std::clock_t endDeq = std::clock();
    double timeDeq = static_cast<double>(endDeq - startDeq) / CLOCKS_PER_SEC * 1000000;

    // 4. Mostrar estado final
    std::cout << "After:  ";
    for (size_t i = 0; i < _vectorArg.size(); ++i) std::cout << _vectorArg[i] << " ";
    std::cout << std::endl;

    // 5. Imprimir Tiempos
    std::cout << "Time to process a range of " << _vectorArg.size() 
              << " elements with std::vector : " << std::fixed << std::setprecision(5) << timeVec << " us" << std::endl;
    
    std::cout << "Time to process a range of " << _dequeArg.size() 
              << " elements with std::deque  : " << std::fixed << std::setprecision(5) << timeDeq << " us" << std::endl;
}

int PmergeMe::getJacobsthal(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return getJacobsthal(n - 1) + 2 * getJacobsthal(n - 2);
}

template <typename T>
void PmergeMe::binaryInsert(T& container, int val, int limitIndex) {
    typename T::iterator itLow = container.begin();
    typename T::iterator itHigh = container.begin() + limitIndex;
    typename T::iterator pos = std::lower_bound(itLow, itHigh, val);
    container.insert(pos, val);
}

void PmergeMe::sortVector(std::vector<int>& arr) {
    size_t n = arr.size();
    if (n <= 1) return;

    bool hasStraggler = (n % 2 != 0);
    int straggler = 0;
    if (hasStraggler) {
        straggler = arr.back();
        arr.pop_back();
    }

    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i < arr.size(); i += 2) {
        if (arr[i] > arr[i+1]) 
            pairs.push_back(std::make_pair(arr[i+1], arr[i]));
        else
            pairs.push_back(std::make_pair(arr[i], arr[i+1]));
    }

    std::vector<int> mainChain;
    for (size_t i = 0; i < pairs.size(); ++i) {
        mainChain.push_back(pairs[i].second);
    }

    sortVector(mainChain);
    std::vector<int> pendChain;

    for (size_t i = 0; i < pairs.size(); ++i) {
        if (pairs[i].second == mainChain[0]) {
            mainChain.insert(mainChain.begin(), pairs[i].first);
            pairs.erase(pairs.begin() + i);
            break;
        }
    }

    std::vector<int> pendingElements;
    
    for (size_t i = 1; i < mainChain.size(); ++i) {
        int currentMax = mainChain[i];
        for (size_t j = 0; j < pairs.size(); ++j) {
            if (pairs[j].second == currentMax) {
                pendingElements.push_back(pairs[j].first);
                pairs.erase(pairs.begin() + j);
                break;
            }
        }
    }

    int jacobIdx = 3; 
    int prevJacob = 1; 
    
    size_t insertedCount = 0; 

    while (insertedCount < pendingElements.size()) {
        int idx = getJacobsthal(jacobIdx) - 1; 
        
        if (idx >= static_cast<int>(pendingElements.size()))
            idx = pendingElements.size() - 1;

        while (idx >= prevJacob - 1 && idx >= 0) {
            if (idx < static_cast<int>(pendingElements.size())) {
                int val = pendingElements[idx];
                std::vector<int>::iterator it = mainChain.begin() + (idx + 1 + insertedCount + 1); 
                if (it > mainChain.end()) it = mainChain.end();
                std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), it, val);
                mainChain.insert(pos, val);
                
                insertedCount++;
            }
            idx--;
        }
        prevJacob = getJacobsthal(jacobIdx);
        jacobIdx++;
    }

    if (hasStraggler) {
        std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
        mainChain.insert(pos, straggler);
    }

    arr = mainChain;
}


void PmergeMe::sortDeque(std::deque<int>& arr) {
    size_t n = arr.size();
    if (n <= 1) return;

    bool hasStraggler = (n % 2 != 0);
    int straggler = 0;
    if (hasStraggler) {
        straggler = arr.back();
        arr.pop_back();
    }

    std::deque<std::pair<int, int> > pairs;
    for (size_t i = 0; i < arr.size(); i += 2) {
        if (arr[i] > arr[i+1]) 
            pairs.push_back(std::make_pair(arr[i+1], arr[i]));
        else
            pairs.push_back(std::make_pair(arr[i], arr[i+1]));
    }

    std::deque<int> mainChain;
    for (size_t i = 0; i < pairs.size(); ++i) {
        mainChain.push_back(pairs[i].second);
    }

    sortDeque(mainChain);

    std::deque<int> pendingElements;
    for (size_t i = 0; i < pairs.size(); ++i) {
        if (pairs[i].second == mainChain[0]) {
            mainChain.push_front(pairs[i].first);
            pairs.erase(pairs.begin() + i);
            break;
        }
    }

    for (size_t i = 1; i < mainChain.size(); ++i) {
        int currentMax = mainChain[i];
        for (size_t j = 0; j < pairs.size(); ++j) {
            if (pairs[j].second == currentMax) {
                pendingElements.push_back(pairs[j].first);
                pairs.erase(pairs.begin() + j);
                break;
            }
        }
    }

    int jacobIdx = 3; 
    int prevJacob = 1; 
    size_t insertedCount = 0;

    while (insertedCount < pendingElements.size()) {
        int idx = getJacobsthal(jacobIdx) - 1; 
        if (idx >= static_cast<int>(pendingElements.size())) idx = pendingElements.size() - 1;

        while (idx >= prevJacob - 1 && idx >= 0) {
            if (idx < static_cast<int>(pendingElements.size())) {
                int val = pendingElements[idx];
                
                std::deque<int>::iterator it = mainChain.begin() + (idx + 1 + insertedCount + 1);
                if (it > mainChain.end()) it = mainChain.end();
                
                std::deque<int>::iterator pos = std::lower_bound(mainChain.begin(), it, val);
                mainChain.insert(pos, val);
                
                insertedCount++;
            }
            idx--;
        }
        prevJacob = getJacobsthal(jacobIdx);
        jacobIdx++;
    }

    if (hasStraggler) {
        std::deque<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
        mainChain.insert(pos, straggler);
    }

    arr = mainChain;
}