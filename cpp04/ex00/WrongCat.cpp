#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    std::cout << ">>>>>>> WrongCat default constructor" << std::endl;
    setType("WrongCat");
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
    setType(other.getType());
}

WrongCat::~WrongCat()
{
    std::cout << ">>>>>>> WrongCat default destructor" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
    if (this == &other)
        return *this;
    setType(other.getType());
    return *this;
}
void WrongCat::makeSound() const
{
    std::cout << "Meow" << std::endl;
}
