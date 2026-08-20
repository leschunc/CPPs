#ifndef FIXED
#define FIXED

#include <iostream>
#include <cmath>
#include <iostream>

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

    float toFloat(void) const;
    int toInt(void) const;

    Fixed &operator=(const Fixed &other);
    Fixed operator++(int num);
    Fixed operator--(int num);
    Fixed &operator--();
    Fixed &operator++();

    bool operator>(const Fixed &other);
    bool operator<(const Fixed &other);
    bool operator>=(const Fixed &other);
    bool operator<=(const Fixed &other);
    bool operator==(const Fixed &other);
    bool operator!=(const Fixed &other);

    Fixed operator+(const Fixed &other);
    Fixed operator-(const Fixed &other);
    Fixed operator*(const Fixed &other);
    Fixed operator/(const Fixed &other);
    
    int getRawBits() const;
    void setRawBits(int const raw);
};

std::ostream& operator<<(std::ostream &os, const Fixed& f);

#endif