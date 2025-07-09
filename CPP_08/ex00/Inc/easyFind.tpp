#pragma once

template <typename T>
int easyfind(const T& container, int value) {
    typename T::const_iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
        throw std::runtime_error("Value not found");
    return static_cast<int>(std::distance(container.begin(), it));
}
