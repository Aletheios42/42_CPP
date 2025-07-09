
#include <iostream>
#include <string>
#include "../Inc/iter.hpp"

template <typename T>
void printElement(T const &x) {
	std::cout << x << std::endl;
}

template <typename T>
void increment(T &x) {
	++x;
}

int main() {
	// Test 1: enteros
	int intArray[] = {1, 2, 3, 4, 5};
	std::cout << "Original intArray:" << std::endl;
	iter(intArray, 5, printElement);
	iter(intArray, 5, increment<int>);
	std::cout << "After increment:" << std::endl;
	iter(intArray, 5, printElement);

	// Test 2: strings
	std::string strArray[] = {"uno", "dos", "tres"};
	std::cout << "\nOriginal strArray:" << std::endl;
	iter(strArray, 3, printElement);

	// Test 3: chars
	char charArray[] = {'A', 'B', 'C'};
	std::cout << "\ncharArray:" << std::endl;
	iter(charArray, 3, printElement);

	// Test 4: const array
	const double doubleArray[] = {3.14, 2.71, 1.41};
	std::cout << "\nconst doubleArray:" << std::endl;
	iter(doubleArray, 3, printElement);

	return 0;
}
