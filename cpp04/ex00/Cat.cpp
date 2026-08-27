#include "Cat.hpp"

Cat::Cat()
{
    std::cout << ">>>>>>> Cat default constructor" << std::endl;
    setType("Cat");
}

Cat::Cat(const Cat &other) : Animal(other)
{
    setType(other.getType());
}

Cat::~Cat()
{
    std::cout << ">>>>>>> Cat default destructor" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
    if (this == &other)
        return *this;
    setType(other.getType());
    return *this;
}

void Cat::makeSound() const
{
    std::cout << "Meow" << std::endl;
}
