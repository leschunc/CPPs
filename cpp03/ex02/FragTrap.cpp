#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    if (DB_LEVEL & DB_CONST)
        say(__FUNCTION__, true);
    setHP(100);
    setEnergy(100);
    setAD(30);
}

FragTrap::FragTrap(const std::string &name)
{
    if (DB_LEVEL & DB_CONST)
        say(__FUNCTION__, true);

    setName(name);
    setHP(100);
    setEnergy(100);
    setAD(30);
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
    if (DB_LEVEL & DB_CONST)
        say(__FUNCTION__, true);

    if (this == &other)
        return;
    setAD(other.getAD());
    setHP(other.getHP());
    setEnergy(other.getEnergy());
    setName(other.getName());
}

FragTrap::~FragTrap()
{
    if (DB_LEVEL & DB_CONST)
        say(__FUNCTION__, true);
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
    if (DB_LEVEL & DB_OVERLD)
        say(__FUNCTION__, true);

    if (this == &other)
        return *this;
    setAD(other.getAD());
    setHP(other.getHP());
    setEnergy(other.getEnergy());
    setName(other.getName());
    return *this;
}

void FragTrap::highFivesGuys()
{
    if (DB_LEVEL & DB_METHOD)
        say(__FUNCTION__, true);
    std::cout << getName() << ": high five!" << std::endl;
}

void FragTrap::attack(const std::string &target)
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
    std::cout << "FragTrap " << getName()
              << " attacks " << target << ", causing "
              << getAD() << " points of damage" << std::endl;
}

void FragTrap::takeDamage(unsigned int amount)
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
    std::cout << "FragTrap " << getName()
              << " takes " << amount << " points of damage" << std::endl;
}

void FragTrap::beRepaired(unsigned int amount)
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
        std::cout << getName() << ": Sorry, will not perform unsafe operation" << std::endl;
        return;
    }
    setHP(getHP() + amount);
    std::cout << "FragTrap " << getName()
              << " is repaired by " << amount << " hit points" << std::endl;
}
