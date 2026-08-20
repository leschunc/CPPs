#ifndef FIXED
#define FIXED

#include <iostream>

class Fixed
{
private:
    int raw;
    static const int frac = 8;

public:
    Fixed();
    Fixed(Fixed &num);
    Fixed &operator=(const Fixed &other);
    int getRawBits() const;
    void setRawBits(int const raw);
    ~Fixed();
};

#endif