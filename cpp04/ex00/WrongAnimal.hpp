#ifndef WRONGANIMAL
#define WRONGANIMAL

#include <iostream>

class WrongAnimal
{
protected:
    std::string type;

public:
    WrongAnimal();
    ~WrongAnimal();

    void setType(const std::string &type);
    const std::string& getType() const;

    void makeSound() const;
};

#endif