#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap()
{
    std::cout << "Default constructor" << std::endl;
    HP = 10;
    Energy = 10;
    AD = 0;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
    std::cout << "Copy constructor" << std::endl;
    this->HP = other.HP;
    this->Energy = other.Energy;
    this->AD = other.AD;
}

ClapTrap::~ClapTrap()
{
    std::cout << "Default destructor" << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap &other)
{
    std::cout << "Assignment overload" << std::endl;

    if (this != &other)
    {
        this->HP = other.HP;
        this->Energy = other.Energy;
        this->AD = other.AD;
    }
    return *this;
}
