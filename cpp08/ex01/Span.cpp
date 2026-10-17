#include "Span.hpp"
#include <iostream>
#include <climits>

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

unsigned int Span::shortestSpan()
{
    if (_vec.size() < 2)
        throw std::out_of_range("not enough elements to search");

    long lowestDist = LONG_MAX;
    long currentDist;

    for (size_t i = 0; i < _vec.size() - 1; i++)
    {
        currentDist = _vec.at(i) - _vec.at(i + 1);
        if (currentDist < 0) currentDist = -currentDist;
        if (currentDist < lowestDist) lowestDist = currentDist;
    }
    return lowestDist;
}

unsigned int Span::longestSpan()
{
    if (_vec.size() < 2)
        throw std::out_of_range("not enough elements to search");

    int biggest = INT_MIN;
    int smallest = INT_MAX;
    for (size_t i = 0; i < _vec.size(); i++)
    {
        if (_vec.at(i) > biggest)
            biggest = _vec.at(i);
        if (_vec.at(i) < smallest)
            smallest = _vec.at(i);
    }
    return biggest - smallest;
}
