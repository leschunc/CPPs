#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <cstdlib>

// this shows I can work with either const or non const animals
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
    delete dog;
    std::cout << "------------" << std::endl;
}

// output example from subject part 1
void subjectOneTest()
{
    const Animal *meta = new Animal();
    const Animal *j = new Dog();
    const Animal *i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;

    meta->makeSound();

    i->makeSound();
    j->makeSound();

    delete meta;
    delete i;
    delete j;
    std::cout << "------------" << std::endl;
}


// Subject part two
void subjectTest()
{
    Animal *animals[10];

    for (size_t i = 0; i < 10; i++)
    {
        if (i % 2 == 0)
            animals[i] = new Cat;
        else
            animals[i] = new Dog;
    }
    for (size_t i = 0; i < 10; i++)
    {
        animals[i]->makeSound();
        delete animals[i];
    }
    std::cout << "------------" << std::endl;
}

// easy test to show a ¿cat? blink is space-time
void schrodTest()
{
    Cat cat;
    Cat catcat(cat);
    std::cout << "------------" << std::endl;
}

// demoes how thoughts in inner scopes get copied to outer scopes
Cat deepCatter()
{
    Cat deespestCat;

    deespestCat.peek()->setThought("out-thought", 0);

    Cat deepCat = deespestCat;

    deespestCat.peek()->setThought("in-thought", 0);

    return deepCat;
}

// same 
void shallowTest()
{
    Cat midCat = deepCatter();

    midCat.makeSound();

    std::cout << midCat.peek()->getThought(0) << std::endl;
    std::cout << "------------" << std::endl;
}

// same 
Dog dogDeeper()
{
    Dog deespestDog;

    deespestDog.peek()->setThought("out-thought", 0);

    Dog deepDog = deespestDog;

    deespestDog.peek()->setThought("in-thought", 0);

    return deepDog;
}

// same 
void dogSameTest()
{
    Dog midDog = dogDeeper();

    midDog.makeSound();

    std::cout << midDog.peek()->getThought(0) << std::endl;
    std::cout << "------------" << std::endl;
}

// deep copy with deletion
void simpleTest()
{
    Cat *a = new Cat;

    a->peek()->setThought("soygato", 0);

    Cat b;

    b = *a;

    a->peek()->setThought("nosoygato", 0);

    delete a;

    std::cout << b.peek()->getThought(0) << std::endl;
    std::cout << "------------" << std::endl;
}

int main()
{
    subjectOneTest();
    
    subjectTest();
    
    shallowTest();
    
    dogSameTest();
    
    copyTest();

    schrodTest();

    simpleTest();

    return 0;
}
