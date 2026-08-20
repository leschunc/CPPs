#include "Fixed.hpp"

Fixed::Fixed()
{
    raw = 0;
}

Fixed::Fixed(int num)
{
    raw = num;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    if (this != &other)
        raw = other.raw;
    return *this;
}

int Fixed::getRawBits() const {
    return (raw);
}

void Fixed::setRawBits(int const raw){
    this->raw = raw;
}

Fixed::~Fixed()
{
}
