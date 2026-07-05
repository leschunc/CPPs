#ifndef WEAPON
#define WEAPON

#include <string>
#include <iostream>

class Weapon
{
private:
    std::string type;

public:
    Weapon();
    Weapon(std::string type);
    const std::string &getType(void) const;
    void setType(std::string type);
    ~Weapon();
};
#endif
