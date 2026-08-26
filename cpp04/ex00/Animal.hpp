#ifndef ANIMAL
#define ANIMAL

#include <iostream>

class Animal
{
protected:
    std::string type;

public:
    Animal();
    ~Animal();

    void setType(const std::string &type);
    std::string &getType();

    void makeSound();
};

#endif