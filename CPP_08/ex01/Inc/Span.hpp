#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <exception>
#include <algorithm>
#include <iostream>

class Span {
private:
    unsigned int _maxSize;
    std::vector<int> _numbers;

public:
    // Constructor parametrizado
    Span(unsigned int N);

    // Constructor copia
    Span(const Span& other);

    // Operador asignación
    Span& operator=(const Span& other);

    // Destructor
    ~Span();

    // Añadir número
    void addNumber(int number);

    // Cálculo spans
    unsigned int shortestSpan() const;
    unsigned int longestSpan() const;

    // Excepciones
    class SpanFullException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class SpanTooSmallException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
};

#endif

