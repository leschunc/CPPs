#ifndef FIXED
#define FIXED

#include <iostream>

class Fixed
{
private:
    int raw;
    int frac;

public:
    Fixed();
    Fixed(const int num);
    Fixed(const float num);
    // Fixed(int num);
    float toFloat(void) const;
    int toInt(void) const;
    Fixed &operator=(const Fixed &other);
    
    int getRawBits() const;
    void setRawBits(int const raw);
    ~Fixed();
};

std::ostream& operator<<(std::ostream &os, const Fixed& f);

#endif

// A constructor that takes a constant integer as a parameter.