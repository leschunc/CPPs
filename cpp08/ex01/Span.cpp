#include "Span.hpp"
#include <iostream>
#include <climits>

Span::Span() : _size(0), _vec(std::vector<int>(_size))
{
    _vec.reserve(0);
}

Span::Span(const Span &ref) : _size(ref._size), _vec(ref._vec)
{
}

Span::~Span()
{
}

Span::Span(unsigned int n) : _size(n), _vec(std::vector<int>(_size))
{
    _vec.reserve(_size);
}

Span &Span::operator=(const Span &ref)
{
    if (this == &ref)
        return *this;
    _size = ref._size;
    _vec = ref._vec;
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

unsigned int Span::shortestSpan() const
{
    if (_vec.size() < 2)
        throw std::out_of_range("not enough elements to search");

    std::vector<int> temp = _vec;
    std::sort(temp.begin(), temp.end());
    int lowest = INT_MAX;
    for (size_t i = 0; i < temp.size() - 1; i++)
    {
        if (temp.at(i + 1) - temp.at(i) < lowest)
            lowest = temp.at(i + 1) - temp.at(i);
    }
    return lowest;
}

unsigned int Span::longestSpan() const
{
    if (_vec.size() < 2)
        throw std::out_of_range("not enough elements to search");

    std::vector<int>::const_iterator biggest = std::max_element(_vec.begin(), _vec.end());
    std::vector<int>::const_iterator smallest = std::min_element(_vec.begin(), _vec.end());

    return *biggest - *smallest;
}
