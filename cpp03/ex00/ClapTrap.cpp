#include "ClapTrap.hpp"

void say(const std::string anything)
{
    std::cout << anything << std::endl;
}

void sayNum(unsigned int value)
{
    std::cout << value << std::endl;
}

ClapTrap::ClapTrap()
{
    if (DB_LEVEL & DB_CONST)
        say(__FUNCTION__);
    setHP(10);
    setEnergy(10);
    setAD(0);
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
    if (DB_LEVEL & DB_CONST)
        say(__FUNCTION__);
    setHP(other.HP);
    setEnergy(other.Energy);
    setAD(other.AD);
}

ClapTrap::~ClapTrap()
{
    if (DB_LEVEL & DB_CONST)
        say(__FUNCTION__);
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    if (DB_LEVEL & DB_OVERLD)
        say(__FUNCTION__);
    if (this != &other)
    {
        HP = other.HP;
        Energy = other.Energy;
        AD = other.AD;
    }
    return *this;
}

unsigned int ClapTrap::getHP() const
{
    if (DB_LEVEL & DB_GETSET)
        say(__FUNCTION__);
    return HP;
}

unsigned int ClapTrap::getEnergy() const
{
    if (DB_LEVEL & DB_GETSET)
        say(__FUNCTION__);
    return Energy;
}

unsigned int ClapTrap::getAD() const
{
    if (DB_LEVEL & DB_GETSET)
        say(__FUNCTION__);
    return AD;
}

void ClapTrap::setHP(unsigned int amount)
{
    if (DB_LEVEL & DB_GETSET)
        say(__FUNCTION__);
    HP = amount;
}

void ClapTrap::setEnergy(unsigned int amount)
{
    if (DB_LEVEL & DB_GETSET)
        say(__FUNCTION__);
    Energy = amount;
}

void ClapTrap::setAD(unsigned int amount)
{
    if (DB_LEVEL & DB_GETSET)
        say(__FUNCTION__);
    AD = amount;
}

void ClapTrap::attack(const std::string &target)
{
    if (DB_LEVEL & DB_METHOD)
        say(__FUNCTION__);
    if (getEnergy() & (1 << 31) || getEnergy() == 0)
    {
        say("Can't attack, no energy");
        return;
    }
    else
        setEnergy(getEnergy() - 1);
    if (getHP() & (1 << 31) || getHP() == 0)
    {
        say("Can't attack, it's dead");
        return;
    }
    say("Attacking ");
    say(target);
    sayNum(getAD());
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (DB_LEVEL & DB_METHOD)
        say(__FUNCTION__);
    if (getHP() & (1 << 31) || getHP() == 0)
    {
        say("Can't take damage, it's dead");
        return;
    }
    if (amount & (1 << 31))
    {
        say("Sorry, will not perform unsafe operation");
        return;
    }
    say("Taking damage: ");
    sayNum(amount);
    setHP(getHP() - amount);
    sayNum(getHP());
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (DB_LEVEL & DB_METHOD)
        say(__FUNCTION__);
    if (getEnergy() & (1 << 31) || getEnergy() == 0)
    {
        say("Can't be repaired, no energy");
        return;
    }
    else
        setEnergy(getEnergy() - 1);
    if (getHP() & (1 << 31) || getHP() == 0)
    {
        say("Can't be repaired, it's dead");
        return;
    }
    if (amount & (1 << 31) || (getHP() + amount) & (1 << 31))
    {
        say("Sorry, will not perform unsafe operation");
        return;
    }
    say("Repairing: ");
    sayNum(amount);
    setHP(getHP() + amount);
    sayNum(getHP());
}
