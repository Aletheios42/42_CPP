#include "../Inc/Span.hpp"
#include <algorithm>

Span::Span(unsigned int N) : _maxSize(N), _numbers() {}

Span::Span(const Span& other) : _maxSize(other._maxSize), _numbers(other._numbers) {}

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        _maxSize = other._maxSize;
        _numbers = other._numbers;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int number) {
    if (_numbers.size() >= _maxSize)
        throw SpanFullException();
    _numbers.push_back(number);
}

unsigned int Span::shortestSpan() const {
    if (_numbers.size() < 2)
        throw SpanTooSmallException();

    std::vector<int> sorted(_numbers);
    std::sort(sorted.begin(), sorted.end());

    unsigned int minSpan = static_cast<unsigned int>(-1);

    for (std::vector<int>::size_type i = 1; i < sorted.size(); ++i) {
        unsigned int diff = static_cast<unsigned int>(sorted[i] - sorted[i - 1]);
        if (diff < minSpan)
            minSpan = diff;
    }
    return minSpan;
}

unsigned int Span::longestSpan() const {
    if (_numbers.size() < 2)
        throw SpanTooSmallException();

    int minVal = *std::min_element(_numbers.begin(), _numbers.end());
    int maxVal = *std::max_element(_numbers.begin(), _numbers.end());

    return static_cast<unsigned int>(maxVal - minVal);
}

const char* Span::SpanFullException::what() const throw() {
    return "Span is already full";
}

const char* Span::SpanTooSmallException::what() const throw() {
    return "Not enough elements to find a span";
}

