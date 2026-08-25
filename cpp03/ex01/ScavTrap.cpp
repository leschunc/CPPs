#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    if (DB_LEVEL & DB_CONST)
        say(__FUNCTION__, true);
    setHP(100);
    setEnergy(50);
    setAD(20);
}

ScavTrap::ScavTrap(const std::string &name)
{
    if (DB_LEVEL & DB_CONST)
        say(__FUNCTION__, true);

    setName(name);
    setHP(100);
    setEnergy(50);
    setAD(20);
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
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

ScavTrap::~ScavTrap()
{
    if (DB_LEVEL & DB_CONST)
        say(__FUNCTION__, true);
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
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

void ScavTrap::guardGate()
{
    if (DB_LEVEL & DB_METHOD)
        say(__FUNCTION__, true);

    std::cout << getName() << " is now in Gate keeper mode" << std::endl;
}

void ScavTrap::attack(const std::string &target)
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
    std::cout << "ScavTrap " << getName()
              << " attacks " << target << ", causing "
              << getAD() << " points of damage" << std::endl;
}

void ScavTrap::takeDamage(unsigned int amount)
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
    std::cout << "ScavTrap " << getName()
              << " takes " << amount << " points of damage" << std::endl;
}

void ScavTrap::beRepaired(unsigned int amount)
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
    std::cout << "ScavTrap " << getName()
              << " is repaired by " << amount << " hit points" << std::endl;
}
