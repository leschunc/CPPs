#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void copyTest()
{
    Animal a;
    const Animal b;
    Animal *c;
    const Animal *d = new Animal;

    a = b;
    c = (Animal *)d;
    c->setType("ai meo deos");
    std::cout << d->getType() << std::endl;

    Cat cat;

    Cat cat2 = cat;

    cat = cat2;

    const Dog *dog = new Dog;

    Dog dog2 = *dog;

    dog2.makeSound();
    dog->makeSound();

    delete c;
    std::cout << "------------" << std::endl;
}

void wrongTest()
{
    const WrongAnimal *ani = new WrongAnimal();
    const WrongAnimal *gatu = new WrongCat();

    ani->makeSound();
    gatu->makeSound();
    std::cout << "------------" << std::endl;
}

void wrongCopyTest()
{
    WrongAnimal a;

    WrongAnimal b;

    WrongCat c;

    WrongCat d;

    c = d;

    b = a;
    std::cout << "------------" << std::endl;
}

int main()
{

    copyTest();

    wrongTest();

    wrongCopyTest();

    const Animal *meta = new Animal();
    const Animal *j = new Dog();
    const Animal *i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;

    meta->makeSound();

    i->makeSound();
    j->makeSound();

    return 0;
}
