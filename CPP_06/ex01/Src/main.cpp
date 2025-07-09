#include "../Inc/Serializer.hpp"
#include <iostream>
#include <cstdlib>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <string> <int_value>\n";
        return 1;
    }

    std::string inputStr = argv[1];
    int value = std::atoi(argv[2]);

    Data data;
    data.s = inputStr;
    data.i = value;

    std::cout << "Original data: " << data << '\n';

    uintptr_t serialized = Serializer::serialize(&data);
    std::cout << "Serialized pointer: " << serialized << '\n';

    Data* deserialized = Serializer::deserialize(serialized);
    std::cout << "Deserialized data: " << *deserialized << '\n';

    if (deserialized == &data)
        std::cout << "Pointers are equal: Serialization successful.\n";
    else
        std::cout << "Pointers differ: Serialization failed.\n";

    return 0;
}

