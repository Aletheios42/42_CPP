#pragma once

#include <cstddef>
#include <iostream>
#include <string>

typedef std::size_t uintptr_t;

struct Data {
    std::string s;
    int i;
};

class Serializer {
private:
    Serializer();
    ~Serializer();
    Serializer(const Serializer&);
    Serializer& operator=(const Serializer&);

public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};

std::ostream& operator<<(std::ostream& os, const Data& d);

