#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    setType("WrongCat");
}

WrongCat::~WrongCat()
{
}

void WrongCat::makeSound() const
{
    std::cout << "Meow" << std::endl;
}
