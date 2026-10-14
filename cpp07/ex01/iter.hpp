#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T, typename F>
void iter(T addr, size_t size, F func)
{
    for (size_t i = 0; i < size; i++)
    {
        func(addr[i]);
    }
};

#endif
