#include "ClapTrap.hpp"

void say(const std::string anything, bool nl)
{
    if (nl)
        std::cout << std::endl;
    std::cout << "    >>>> " << anything;
    if (nl)
        std::cout << std::endl
                  << std::endl;
}

ClapTrap::ClapTrap()
{
    if (DB_LEVEL & DB_CONST)
        say(__FUNCTION__, true);
}

ClapTrap::ClapTrap(const std::string &name)
{
    if (DB_LEVEL & DB_CONST)
        say(__FUNCTION__, true);
    setName(name);
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
    if (DB_LEVEL & DB_CONST)
        say(__FUNCTION__, true);
    setName(other.name);
    setHP(other.HP);
    setEnergy(other.Energy);
    setAD(other.AD);
}

ClapTrap::~ClapTrap()
{
    if (DB_LEVEL & DB_CONST)
        say(__FUNCTION__, true);
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    if (DB_LEVEL & DB_OVERLD)
        say(__FUNCTION__, true);
    if (this != &other)
    {
        name = other.name;
        HP = other.HP;
        Energy = other.Energy;
        AD = other.AD;
    }
    return *this;
}

std::string ClapTrap::getName() const
{
    if (DB_LEVEL & DB_GETSET)
        say(__FUNCTION__, true);
    return name;
}

unsigned int ClapTrap::getHP() const
{
    if (DB_LEVEL & DB_GETSET)
        say(__FUNCTION__, true);
    return HP;
}

unsigned int ClapTrap::getEnergy() const
{
    if (DB_LEVEL & DB_GETSET)
        say(__FUNCTION__, true);
    return Energy;
}

unsigned int ClapTrap::getAD() const
{
    if (DB_LEVEL & DB_GETSET)
        say(__FUNCTION__, true);
    return AD;
}

void ClapTrap::setName(const std::string &name)
{
    if (DB_LEVEL & DB_GETSET)
        say(__FUNCTION__, true);
    this->name = name;
}

void ClapTrap::setHP(unsigned int amount)
{
    if (DB_LEVEL & DB_GETSET)
        say(__FUNCTION__, true);
    HP = amount;
}

void ClapTrap::setEnergy(unsigned int amount)
{
    if (DB_LEVEL & DB_GETSET)
        say(__FUNCTION__, true);
    Energy = amount;
}

void ClapTrap::setAD(unsigned int amount)
{
    if (DB_LEVEL & DB_GETSET)
        say(__FUNCTION__, true);
    AD = amount;
}

void ClapTrap::attack(const std::string &target)
{
    if (DB_LEVEL & DB_METHOD)
        say(__FUNCTION__, true);
    if (getEnergy() & (1 << 31) || getEnergy() == 0)
    {
        std::cout << getName() << ": can't attack, no energy" << std::endl;
        return;
    }
    else
        setEnergy(getEnergy() - 1);
    if (getHP() & (1 << 31) || getHP() == 0)
    {
        std::cout << getName() << ": can't attack, it's dead" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << getName()
              << " attacks " << target << ", causing "
              << getAD() << " points of damage" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (DB_LEVEL & DB_METHOD)
        say(__FUNCTION__, true);
    if (getHP() & (1 << 31) || getHP() == 0)
    {
        std::cout << getName() << ": can't take damage, it's dead" << std::endl;
        return;
    }
    if (amount & (1 << 31))
    {
        std::cout << getName() << ": Sorry, will not perform unsafe operation" << std::endl;
        return;
    }
    setHP(getHP() - amount);
    std::cout << "ClapTrap " << getName()
              << " takes " << amount << " points of damage" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (DB_LEVEL & DB_METHOD)
        say(__FUNCTION__, true);
    if (getEnergy() & (1 << 31) || getEnergy() == 0)
    {
        std::cout << getName() << ": can't be repaired, no energy" << std::endl;
        return;
    }
    else
        setEnergy(getEnergy() - 1);
    if (getHP() & (1 << 31) || getHP() == 0)
    {
        std::cout << getName() << ": can't be repaired, it's dead" << std::endl;
        return;
    }
    if (amount & (1 << 31) || (getHP() + amount) & (1 << 31))
    {
        say(getName(), false);
        say(": Sorry, will not perform unsafe operation", true);
        return;
    }
    setHP(getHP() + amount);
    std::cout << "ClapTrap " << getName()
              << " is repaired by " << amount << " hit points" << std::endl;
}
