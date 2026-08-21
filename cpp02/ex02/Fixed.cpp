#include "Fixed.hpp"

Fixed::Fixed()
{
    setRawBits(0);
}

Fixed::Fixed(int num)
{
    setRawBits(num << frac);
}

Fixed::Fixed(float num)
{
    setRawBits(roundf(num * (1 << frac)));
}

Fixed::Fixed(const Fixed &num)
{
    setRawBits(num.getRawBits());
}

Fixed::~Fixed()
{
}

Fixed &Fixed::operator=(const Fixed &other)
{
    if (this != &other)
        setRawBits(other.raw);
    return *this;
}

bool Fixed::operator>(const Fixed &other) const
{
    return (getRawBits() > other.getRawBits());
}

bool Fixed::operator<(const Fixed &other) const
{
    return (getRawBits() < other.getRawBits());
}

bool Fixed::operator<=(const Fixed &other) const
{
    return (getRawBits() <= other.getRawBits());
}

bool Fixed::operator>=(const Fixed &other) const
{
    return (getRawBits() >= other.getRawBits());
}

bool Fixed::operator==(const Fixed &other) const
{
    return (getRawBits() == other.getRawBits());
}

bool Fixed::operator!=(const Fixed &other) const
{
    return (getRawBits() != other.getRawBits());
}

Fixed Fixed::operator+(const Fixed &other) const
{
    Fixed result;

    result.setRawBits(getRawBits() + other.getRawBits());
    return (result);
}

Fixed Fixed::operator-(const Fixed &other) const
{
    Fixed result;

    result.setRawBits(getRawBits() - other.getRawBits());
    return (result);
}

Fixed Fixed::operator*(const Fixed &other) const
{
    Fixed result;
    result.setRawBits(((int64_t)getRawBits() * other.getRawBits()) >> frac);
    return (result);
}

Fixed Fixed::operator/(const Fixed &other) const
{
    Fixed result;
    result.setRawBits((int64_t)((getRawBits() << frac ) / other.getRawBits()) );
    return (result);
}

Fixed &Fixed::operator++()
{
    setRawBits(getRawBits() + 1);
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed result(*this);
    setRawBits(getRawBits() + 1);
    return (result);
}

Fixed &Fixed::operator--()
{
    setRawBits(getRawBits() - 1);
    return (*this);
}

Fixed Fixed::operator--(int)
{
    Fixed result(*this);
    setRawBits(getRawBits() - 1);
    return (result);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    return (a > b) ? a : b;
}

int Fixed::toInt(void) const
{
    return (raw >> frac);
}

float Fixed::toFloat(void) const
{
    return ((float)raw / (1 << frac));
}

int Fixed::getRawBits() const
{
    return (raw);
}

void Fixed::setRawBits(int const raw)
{
    this->raw = raw;
}

std::ostream &operator<<(std::ostream &os, const Fixed &f)
{
    os << f.toFloat();
    return os;
}
