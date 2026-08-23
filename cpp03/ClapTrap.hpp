#ifndef CLAPTRAP
#define CLAPTRAP
#include <iostream>
#define DEBUG 0

class ClapTrap
{
private:
    unsigned int HP;
    unsigned int Energy;
    unsigned int AD;

public:
    ClapTrap();
    ClapTrap(const ClapTrap &other);
    ~ClapTrap();
    ClapTrap &operator=(ClapTrap &other);

    unsigned int getHP() const;
    unsigned int getEnergy() const;
    unsigned int getAD() const;

    void setHP(unsigned int amount);
    void setEnergy(unsigned int amount);
    void setAD(unsigned int amount);

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

void say(std::string anything);
void sayNum(unsigned int value);

#endif
