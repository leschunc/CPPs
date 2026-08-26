#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
}

WrongAnimal::~WrongAnimal()
{
}

const std::string & WrongAnimal::getType() const
{
    return type;
}

void WrongAnimal::setType(const std::string &type)
{
    this->type = type;
}

void WrongAnimal::makeSound() const
{
    std::cout << "Making WrongAnimal sounds" << std::endl;
}
