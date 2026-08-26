#include "Animal.hpp"

Animal::Animal()
{
}

Animal::~Animal()
{
}

void Animal::setType(const std::string &type)
{
    this->type = type;
}
std::string &Animal::getType()
{
    return type;
}

void Animal::makeSound()
{
    std::cout << "Making animal sounds" << std::endl;
}
