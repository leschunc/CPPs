#include "Dog.hpp"

Dog::Dog()
{
    std::cout << ">>>>>>> Dog default constructor" << std::endl;
    setType("Dog");
}

Dog::Dog(const Dog &other) : Animal(other)
{
    setType(other.getType());
}

Dog::~Dog()
{
    std::cout << ">>>>>>> Dog default destructor" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
    if (this == &other)
        return *this;
    setType(other.getType());
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "Bark" << std::endl;
}
