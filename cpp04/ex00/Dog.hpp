#ifndef DOG
#define DOG

#include "Animal.hpp"

class Dog : public Animal
{
private:
public:
    Dog();
    ~Dog();
    void makeSound() const;
};

#endif