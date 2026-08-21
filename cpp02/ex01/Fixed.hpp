#ifndef FIXED
#define FIXED

#include <iostream>
#include <cmath>

class Fixed
{
private:
    int raw;
    static const int frac = 8;

public:
    Fixed();
    Fixed(const int num);
    Fixed(const float num);
    Fixed(const Fixed &num);
    ~Fixed();
    
    Fixed &operator=(const Fixed &other);
    
    int getRawBits() const;
    void setRawBits(int const raw);
    
    int toInt(void) const;
    float toFloat(void) const;
};

std::ostream& operator<<(std::ostream &os, const Fixed& f);

#endif