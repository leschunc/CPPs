#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout << ">>> ClapTrap default constructor" << std::endl;
    setName("genericName");
    setHP(10);
    setEnergy(10);
    setAD(0);
}

ClapTrap::ClapTrap(const std::string &name)
{
    std::cout << ">>> ClapTrap parameterized constructor" << std::endl;
    setName(name);
    setHP(10);
    setEnergy(10);
    setAD(0);
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
    std::cout << ">>> ClapTrap copy constructor" << std::endl;
    setName(other.name);
    setHP(other.HP);
    setEnergy(other.Energy);
    setAD(other.AD);
}

ClapTrap::~ClapTrap()
{
    std::cout << ">>> ClapTrap default destructor" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    std::cout << ">>> Assignment operator overload" << std::endl;
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
    return name;
}

int ClapTrap::getHP() const
{
    return HP;
}

int ClapTrap::getEnergy() const
{
    return Energy;
}

int ClapTrap::getAD() const
{
    return AD;
}

void ClapTrap::setName(const std::string &name)
{
    this->name = name;
}

void ClapTrap::setHP(int amount)
{
    HP = amount;
}

void ClapTrap::setEnergy(int amount)
{
    Energy = amount;
}

void ClapTrap::setAD(int amount)
{
    AD = amount;
}

void ClapTrap::attack(const std::string &target)
{
    if (getEnergy() <= 0)
    {
        std::cout << getName() << " can't attack, no energy" << std::endl;
        return;
    }
    if (getHP() <= 0)
    {
        std::cout << getName() << " can't attack, it's dead" << std::endl;
        return;
    }
    setEnergy(getEnergy() - 1);
    std::cout << "ClapTrap " << getName()
              << " attacks " << target << ", causing "
              << getAD() << " points of damage" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (getEnergy() <= 0)
    {
        std::cout << getName() << ": can't take damage: no energy" << std::endl;
        return;
    }
    if (getHP() <= 0)
    {
        std::cout << getName() << ": can't take damage: it's dead" << std::endl;
        return;
    }
    if (amount > __INT_MAX__ || (getHP() - (int)amount) > getHP())
    {
        std::cout << getName() << ": unsafe operation" << std::endl;
        return;
    }
    setHP(getHP() - amount);
    std::cout << "ClapTrap " << getName()
              << " takes " << amount << " points of damage" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (getEnergy() <= 0)
    {
        std::cout << getName() << ": can't be repaired: no energy" << std::endl;
        return;
    }
    if (getHP() <= 0)
    {
        std::cout << getName() << ": can't be repaired: it's dead" << std::endl;
        return;
    }
    if (amount > __INT_MAX__ || (getHP() + (int)amount) < getHP())
    {
        std::cout << getName() << ": unsafe operation" << std::endl;
        return;
    }
    setHP(getHP() + amount);
    setEnergy(getEnergy() - 1);
    std::cout << "ClapTrap " << getName()
              << " is repaired by " << amount << " hit points" << std::endl;
}
