#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <iostream>

class ClapTrap
{
private:
    std::string name;
    int HP;
    int Energy;
    int AD;

public:
    ClapTrap();
    ClapTrap(const std::string &name);
    ClapTrap(const ClapTrap &other);
    ~ClapTrap();
    
    ClapTrap &operator=(const ClapTrap &other);

    std::string getName() const;
    int getHP() const;
    int getEnergy() const;
    int getAD() const;

    void setName(const std::string &name);
    void setHP(int amount);
    void setEnergy(int amount);
    void setAD(int amount);

    void attack(const std::string &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

#endif
