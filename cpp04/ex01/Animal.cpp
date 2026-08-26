#include "Animal.hpp"

Animal::Animal()
{
    std::cout << ">>>>>>> Animal default constructor" << std::endl;
}

Animal::~Animal()
{
    std::cout << ">>>>>>> Animal default destructor" << std::endl;
}

Animal::Animal(const Animal &copy)
{
    std::cout << ">>>>>>> Animal copy constructor" << std::endl;
    setType(copy.getType());
}

const std::string &Animal::getType() const
{
    return type;
}

Animal &Animal::operator=(const Animal &copy)
{
    std::cout << ">>>>>>> Animal assignment operator overload" << std::endl;
    if (this == &copy)
        return *this;
    setType(copy.getType());
    return *this;
}

void Animal::setType(const std::string &type)
{
    this->type = type;
}

void Animal::makeSound() const
{
    std::cout << "Wiiiiiiiiiii" << std::endl;
}
