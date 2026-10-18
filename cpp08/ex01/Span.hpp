#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>
#include <cstdlib>
#include <algorithm>

class Span
{
private:
    unsigned int _size;
    std::vector<int> _vec;
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
    unsigned int myShortest();
    unsigned int myLongest();

    template <typename T>
    void fill(T curr, T end)
    {
        for (; curr != end; curr++)
            addNumber(*curr);
    }
};

#endif
