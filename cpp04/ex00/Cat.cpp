#include "Cat.hpp"

Cat::Cat()
{
    setType("Cat");
}

Cat::~Cat()
{
}

void Cat::makeSound() const
{
    std::cout << "Meow" << std::endl;
}
