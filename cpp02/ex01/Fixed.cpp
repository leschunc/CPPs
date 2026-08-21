#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor" << std::endl;
    raw = 0;
}

Fixed::Fixed(int num)
{
    std::cout << "Int constructor" << std::endl;
    setRawBits(num << frac);
}

Fixed::Fixed(float num)
{
    std::cout << "Float constructor" << std::endl;
    setRawBits(roundf(num * (1 << frac)));
}

Fixed::Fixed(const Fixed& num)
{
    std::cout << "Fixed class constructor" << std::endl;
    setRawBits(num.raw);
}

Fixed::~Fixed()
{
    std::cout << "Default destructor" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Assignment operator overload" << std::endl;
    if (this != &other)
        setRawBits(other.raw);
    return *this;
}

int Fixed::getRawBits() const
{
    std::cout << "Getter" << std::endl;
    return (raw);
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "Setter" << std::endl;
    this->raw = raw;
}

int Fixed::toInt(void) const
{
    // std::cout << "toInt conversion" << std::endl;
    return (raw >> frac);
}

float Fixed::toFloat(void) const
{
    // std::cout << "toFloat conversion" << std::endl;
    return ((float)raw / (1 << frac));
}

std::ostream& operator<<(std::ostream &that, const Fixed &f)
{
    // std::cout << "Insertion operator overload to ostream class" << std::endl;
    return (that << f.toFloat());
}
