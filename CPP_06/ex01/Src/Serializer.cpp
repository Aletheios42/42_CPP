#include "../Inc/Serializer.hpp"

Serializer::~Serializer() {}

Serializer::Serializer(const Serializer& other) {
    (void)other;
}

Serializer& Serializer::operator=(const Serializer& other) {
    (void)other;
    return *this;
}

uintptr_t Serializer::serialize(Data* ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
    return reinterpret_cast<Data*>(raw);
}

std::ostream& operator<<(std::ostream& os, const Data& d) {
    os << "Data{ s: \"" << d.s << "\", i: " << d.i << " }";
    return os;
}

