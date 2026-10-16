#ifndef SPAN_H
#define SPAN_H

#include <vector>

class Span
{
private:
    unsigned int _size;
    std::vector<int> *vec;

public:
    Span();
    Span(const Span &ref);
    Span(unsigned int n);
    ~Span();
    Span &operator=(const Span &ref);

    // void addNumber(int num);
    // int shortestSpan();
    // int longestSpan();
};

#endif