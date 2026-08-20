#include "Fixed.hpp"

Fixed::Fixed()
{
    raw = 0;
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
    setRawBits(num.raw);
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

bool Fixed::operator>(const Fixed &other)
{
    return (this->getRawBits() > other.getRawBits());
}

bool Fixed::operator<(const Fixed &other)
{
    return (this->getRawBits() < other.getRawBits());
}

bool Fixed::operator<=(const Fixed &other)
{
    return (this->getRawBits() <= other.getRawBits());
}

bool Fixed::operator>=(const Fixed &other)
{
    return (this->getRawBits() >= other.getRawBits());
}

bool Fixed::operator==(const Fixed &other)
{
    return (this->getRawBits() == other.getRawBits());
}

Fixed Fixed::operator+(const Fixed &other)
{
    Fixed result;

    result.setRawBits(this->getRawBits() + other.getRawBits());
    return (result);
}

Fixed Fixed::operator-(const Fixed &other)
{
    Fixed result;

    result.setRawBits(this->getRawBits() - other.getRawBits());
    return (result);
}

Fixed Fixed::operator*(const Fixed &other)
{
    Fixed result(this->toFloat() * other.toFloat());
    return (result);
}

Fixed Fixed::operator/(const Fixed &other)
{
    Fixed result(this->toFloat() / other.toFloat());

    return (result);
}

bool Fixed::operator!=(const Fixed &other)
{
    return (this->getRawBits() != other.getRawBits());
}

// Fixed operator++(int n)
// {

// }
// Fixed operator--(int n)
// {

// }
// Fixed &operator--()
// {

// }

Fixed& Fixed::operator++()
{
    this->setRawBits(this->getRawBits() + 1);
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed result(*this);
    this->setRawBits(this->getRawBits() + 1);
    return (result);
}

Fixed& Fixed::operator--()
{
    this->setRawBits(this->getRawBits() - 1);
    return (*this);
}

Fixed Fixed::operator--(int)
{
    Fixed result(*this);
    this->setRawBits(this->getRawBits() - 1);
    return (result);
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
