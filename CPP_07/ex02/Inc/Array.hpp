#pragma once

#include <exception>

template <typename T>
class Array {
private:
    T* _data;
    unsigned int _size;

public:
    Array();
    explicit Array(unsigned int n);
    Array(const Array& other);
    Array& operator=(const Array& other);
    ~Array();

    T& operator[](unsigned int index);
    const T& operator[](unsigned int index) const;

    unsigned int size() const;

    class OutOfBoundsException : public std::exception {
        public:
            virtual const char* what() const throw() {
                return "Array index out of bounds";
            }
    };
};


#include "Array.tpp"
