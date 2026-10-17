#include "Span.hpp"
#include <iostream>

Span::Span() : _size(0)
{
    _vec = std::vector<int>(_size);
}

Span::Span(const Span &ref)
{
    if (this == &ref)
        return;
    _vec = ref._vec;
    _size = ref._size;
}

Span::~Span()
{
}

Span::Span(unsigned int n) : _size(n)
{
    _vec = std::vector<int>();
}

Span &Span::operator=(const Span &ref)
{
    if (this == &ref)
        return *this;
    _vec = ref._vec;
    _size = ref._size;
    return *this;
}

void Span::addNumber(int num)
{
    if (_vec.size() < _size)
        _vec.push_back(num);
    else
        throw std::out_of_range("out of range");
}

void Span::disp()
{
    for (size_t i = 0; i < _vec.size(); i++)
        std::cout << _vec.at(i) << " ";
    std::cout << std::endl;
}

// int Span::shortestSpan()
// {
//     for (size_t i = 0; i < vec.size(); i++)
//     {
//         std::cout << "wee\n";
//     }
//     return 1;
// }

// int longestSpan()
// {
// }
