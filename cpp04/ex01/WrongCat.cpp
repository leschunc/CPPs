#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    std::cout << ">>>>>>> WrongCat default constructor" << std::endl;
    setType("WrongCat");
}

WrongCat::~WrongCat()
{
    std::cout << ">>>>>>> WrongCat default destructor" << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << "Meow" << std::endl;
}
