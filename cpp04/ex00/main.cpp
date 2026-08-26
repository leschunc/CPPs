#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal *meta = new Animal();
    const Animal *j = new Dog();
    const Animal *i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    
    meta->makeSound();
    
    i->makeSound();
    j->makeSound();

    const WrongAnimal *ani = new WrongAnimal();
    const WrongAnimal *gatu = new WrongCat();

    ani->makeSound();
    gatu->makeSound();

    return 0;
}
