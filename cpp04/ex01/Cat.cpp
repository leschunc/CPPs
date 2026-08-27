#include "Cat.hpp"

Cat::Cat()
{
    std::cout << ">>>>>>> Cat default constructor" << std::endl;
    setType("Cat");
}

Cat::Cat(const Cat &copy) : Animal (copy)
{
    std::cout << ">>>>>>> Cat copy constructor" << std::endl;
    setType(copy.getType());
    brain = copy.brain;
}

Cat::~Cat()
{
    std::cout << ">>>>>>> Cat default destructor" << std::endl;
}

Cat &Cat::operator=(const Cat &copy)
{
    std::cout << ">>>>>>> Cat assignment operator overload" << std::endl;
    if (this == &copy)
        return *this;
    setType(copy.getType());
    brain = copy.brain;
    return *this;
}

void Cat::makeSound() const
{
    std::cout << "Meow" << std::endl;
}

Brain &Cat::peek()
{
    return this->brain;
}
