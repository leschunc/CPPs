#include "ClapTrap.hpp"

void say(std::string anything)
{
    std::cout << anything << std::endl;
}

ClapTrap::ClapTrap()
{
    say(__FUNCTION__);
    setHP(10);
    setEnergy(10);
    setAD(0);
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
    say(__FUNCTION__);
    setHP(other.HP);
    setEnergy(other.Energy);
    setAD(other.AD);
}

ClapTrap::~ClapTrap()
{
    say(__FUNCTION__);
}

ClapTrap &ClapTrap::operator=(ClapTrap &other)
{
    say(__FUNCTION__);
    if (this != &other)
    {
        HP = other.HP;
        Energy = other.Energy;
        AD = other.AD;
    }
    return *this;
}

int ClapTrap::getHP() const
{
    say(__FUNCTION__);
    return HP;
}
int ClapTrap::getEnergy() const
{
    say(__FUNCTION__);
    return Energy;
}
int ClapTrap::getAD() const
{
    say(__FUNCTION__);
    return AD;
}

void ClapTrap::setHP(int amount)
{
    say(__FUNCTION__);
    HP = amount;
}
void ClapTrap::setEnergy(int amount)
{
    say(__FUNCTION__);
    Energy = amount;
}
void ClapTrap::setAD(int amount)
{
    say(__FUNCTION__);
    AD = amount;
}
