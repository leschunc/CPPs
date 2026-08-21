#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor" << std::endl;
    setRawBits(0);
}

Fixed::Fixed(const Fixed &num)
{
    std::cout << "Copy constructor" << std::endl;
    setRawBits(num.getRawBits());
}

Fixed::~Fixed()
{
    std::cout << "Default destructor" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Assignment overload" << std::endl;
    if (this != &other)
        setRawBits(other.getRawBits());
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
