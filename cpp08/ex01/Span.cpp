#include "Span.hpp"

Span::Span()
{
    _size = 0;
    vec = new std::vector<int>(0);
}

Span::Span(const Span &ref)
{
    if (this == &ref)
        return;
    _size = ref._size;
    vec = new std::vector<int>(ref._size);
    for (unsigned int i = 0; i < _size; i++)
        vec->at(i) = ref.vec->at(i);
}

Span::~Span()
{
    delete vec;
}

Span::Span(unsigned int n) : _size(n)
{
    vec = new std::vector<int>(n);
    for (unsigned int i = 0; i < _size; i++)
        vec->at(i) = 0;
}

Span &Span::operator=(const Span &ref)
{
    if (this == &ref)
        return *this;
    // if (vec)
    delete vec;
    this->vec = new std::vector<int>(ref._size);
    for (unsigned int i = 0; i < _size; i++)
        vec->at(i) = ref.vec->at(i);
    return *this;
}

// void addNumber(int num)
// {
// }
// int shortestSpan()
// {
// }
// int longestSpan()
// {
// }
