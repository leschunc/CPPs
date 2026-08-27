#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <cstdlib>

// Subject tests
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
    
    subjectTest();
    
    shallowTest();
    
    dogSameTest();
    
    schrodTest();

    simpleTest();

    return 0;
}
