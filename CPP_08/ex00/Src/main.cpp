#include "../Inc/easyFind.hpp"
#include <iostream>
#include <vector>

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    std::vector<int> v(arr, arr + sizeof(arr)/sizeof(arr[0]));

    try {
        int idx = easyfind(v, 30);
        std::cout << "Found 30 at index " << idx << '\n';
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    try {
        int idx = easyfind(v, 99);
        std::cout << "Found 99 at index " << idx << '\n';
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    return 0;
}
