#include "Dog.hpp"

Dog::Dog()
{
    std::cout << ">>>>>>> Dog default constructor" << std::endl;
    setType("Dog");
    brain = new Brain;
}

Dog::Dog(const Dog &copy) : Animal (copy)
{
    std::cout << ">>>>>>> Dog copy constructor" << std::endl;
    setType(copy.getType());
    brain = new Brain;
    *brain = *copy.brain;
}

Dog::~Dog()
{
    std::cout << ">>>>>>> Dog default destructor" << std::endl;
    delete brain;
}

Dog &Dog::operator=(const Dog &copy)
{
    std::cout << ">>>>>>> Dog assignment operator overload" << std::endl;
    if (this == &copy)
        return *this;
    setType(copy.getType());
    *brain = *copy.brain;
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "Bark" << std::endl;
}

Brain *Dog::peek()
{
    return this->brain;
}
