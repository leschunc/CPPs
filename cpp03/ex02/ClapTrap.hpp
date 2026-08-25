#ifndef CLAPTRAP
#define CLAPTRAP
#include <iostream>

#define DB_LEVEL DB_EVAL

enum e_debug
{
    DB_NONE,
    DB_CONST = 1 << 0,
    DB_GETSET = 1 << 1,
    DB_OVERLD = 1 << 2,
    DB_METHOD = 1 << 3,
    DB_EVAL = DB_CONST | DB_OVERLD | DB_METHOD,
    DB_ALL = DB_CONST | DB_GETSET | DB_OVERLD | DB_METHOD,
};

class ClapTrap
{
protected:
    std::string name;
    unsigned int HP;
    unsigned int Energy;
    unsigned int AD;

public:
    ClapTrap();
    ClapTrap(const std::string &name);
    ClapTrap(const ClapTrap &other);
    ~ClapTrap();
    ClapTrap &operator=(const ClapTrap &other);

    std::string getName() const;
    unsigned int getHP() const;
    unsigned int getEnergy() const;
    unsigned int getAD() const;

    void setName(const std::string &name);
    void setHP(unsigned int amount);
    void setEnergy(unsigned int amount);
    void setAD(unsigned int amount);

    void attack(const std::string &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

void say(const std::string anything, bool nl);

#endif
