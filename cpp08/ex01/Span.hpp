#ifndef SPAN_H
#define SPAN_H

#include <vector>
#include <stdexcept>
#include <cstdlib>

class Span
{
private:
    std::vector<int> _vec;
    unsigned int _size;

public:
    Span();
    Span(const Span &ref);
    Span(unsigned int n);
    ~Span();
    Span &operator=(const Span &ref);

    void addNumber(int num);
    void disp();
    // int shortestSpan();
    // int longestSpan();
};

#endif
