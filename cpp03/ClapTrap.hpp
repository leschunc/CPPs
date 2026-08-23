#ifndef CLAPTRAP
#define CLAPTRAP
#include <iostream>

class ClapTrap
{
private:
    int HP;
    int Energy;
    int AD;

public:
    ClapTrap();
    ClapTrap(const ClapTrap &other);
    ~ClapTrap();
    ClapTrap &operator=(ClapTrap &other);

    int getHP() const;
    int getEnergy() const;
    int getAD() const;

    void setHP(int amount);
    void setEnergy(int amount);
    void setAD(int amount);
};

#endif