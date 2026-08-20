#include "Fixed.hpp"

Fixed::Fixed()
{
    raw = 0;
}

Fixed::Fixed(int num)
{
    raw = num * 100;
    frac = 8;
}

Fixed::Fixed(float num)
{
    raw = (int)num * 100;
    frac = 8;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    if (this != &other)
        raw = other.raw;
    return *this;
}

std::ostream& operator<<(std::ostream &os, const Fixed &f)
{
    os << f.toFloat();
    return os;
}

float Fixed::toFloat(void) const
{
    return ((float)(raw / 100));
}

int Fixed::toInt(void) const
{
    return ((int)(raw / 100));
}

int Fixed::getRawBits() const
{
    return (raw);
}

void Fixed::setRawBits(int const raw)
{
    this->raw = raw;
}

Fixed::~Fixed()
{
}

// And add the following function to the Fixed class files:
// • An overload of the insertion («) operator that inserts a floating-point representation
// of the fixed-point number into the output stream object passed as a parameter.