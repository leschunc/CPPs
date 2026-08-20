#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor" << std::endl;
    raw = 0;
}

Fixed::Fixed(Fixed &num)
{
    std::cout << "Copy constructor" << std::endl;
    raw = num.raw;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Assignment overload" << std::endl;
    if (this != &other)
        raw = other.raw;
    return *this;
}

int Fixed::getRawBits() const {
    std::cout << "Getter RawBits" << std::endl;
    return (raw);
}

void Fixed::setRawBits(int const raw){
    std::cout << "Setter RawBits" << std::endl;
    this->raw = raw;
}

Fixed::~Fixed()
{
    std::cout << "Default destructor" << std::endl;
}
