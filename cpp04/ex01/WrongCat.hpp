#ifndef WRONGCAT
#define WRONGCAT

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
private:
public:
    WrongCat();
    ~WrongCat();

    void makeSound() const ;
};

#endif