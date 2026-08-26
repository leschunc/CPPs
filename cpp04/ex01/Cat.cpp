#include "Cat.hpp"

Cat::Cat()
{
    std::cout << ">>>>>>> Cat default constructor" << std::endl;
    setType("Cat");
}

Cat::~Cat()
{
    std::cout << ">>>>>>> Cat default destructor" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Meow" << std::endl;
}
