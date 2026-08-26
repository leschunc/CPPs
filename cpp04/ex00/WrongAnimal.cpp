#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    std::cout << ">>>>>>> WrongAnimal default constructor" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
    std::cout << ">>>>>>> WrongAnimal copy constructor" << std::endl;

    setType(copy.getType());
}

WrongAnimal::~WrongAnimal()
{
    std::cout << ">>>>>>> WrongAnimal default destructor" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &copy)
{
    std::cout << ">>>>>>> WrongAnimal assignment operator overload" << std::endl;

    if (this == &copy)
        return *this;
    setType(copy.getType());
    return *this;
}

const std::string &WrongAnimal::getType() const
{
    return type;
}

void WrongAnimal::setType(const std::string &type)
{
    this->type = type;
}

void WrongAnimal::makeSound() const
{
    std::cout << "aodshdahiosdajiosdaojidasiojasdoi" << std::endl;
}
