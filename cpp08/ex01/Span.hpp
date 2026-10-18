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

public:
    Span();
    Span(const Span &ref);
    ~Span();
    Span &operator=(const Span &ref);
    Span(unsigned int n);

    void addNumber(int num);
    void disp();
    unsigned int shortestSpan() const;
    unsigned int longestSpan() const;

    template <typename T>
    void fill(T curr, T end)
    {
        for (; curr != end; curr++)
            addNumber(*curr);
    }
};

#endif
