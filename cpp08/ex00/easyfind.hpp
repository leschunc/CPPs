#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>

template <typename T>
void easyfind(T container, int value)
{
    if (std::find(container.begin(), container.end(), value) != container.end())
        std::cout << "it's here\n" << *(std::find(container.begin(), container.end(), value)) << "\n";
    else
        throw std::out_of_range("element not found: out of range");
}

#endif
