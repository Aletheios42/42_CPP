#pragma once

#include <iostream>

template <typename T>
void iter(T* array, int length, void (*func)(T&)) {
	for (int i = 0; i < length; ++i)
		func(array[i]);
}

template <typename T>
void iter(T const* array, int length, void (*func)(T const&)) {
	for (int i = 0; i < length; ++i)
		func(array[i]);
}
