#include "Animal.hpp"

Animal::Animal()
{
}

Animal::~Animal()
{
}

const std::string & Animal::getType() const
{
    return type;
}

void Animal::setType(const std::string &type)
{
    this->type = type;
}

void Animal::makeSound() const
{
    std::cout << "Making animal sounds" << std::endl;
}
