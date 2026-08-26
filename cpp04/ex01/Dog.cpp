#include "Dog.hpp"

Dog::Dog()
{
    std::cout << ">>>>>>> Dog default constructor" << std::endl;
    setType("Dog");
}

Dog::~Dog()
{
    std::cout << ">>>>>>> Dog default destructor" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Bark" << std::endl;
}
