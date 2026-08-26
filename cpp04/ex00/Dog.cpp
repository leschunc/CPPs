#include "Dog.hpp"

Dog::Dog()
{
    setType("Dog");
}

Dog::~Dog()
{
}

void Dog::makeSound() const
{
    std::cout << "Bark" << std::endl;
}
