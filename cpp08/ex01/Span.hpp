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
    Span();
    Span &operator=(const Span &ref);

public:
    Span(const Span &ref);
    Span(unsigned int n);
    ~Span();

    void addNumber(int num);
    void disp();
    unsigned int shortestSpan();
    unsigned int longestSpan();
    // void fill();
};

#endif
