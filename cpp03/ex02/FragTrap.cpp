#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    std::cout << ">>> FragTrap default constructor" << std::endl;
    setName("genericName");
    setHP(100);
    setEnergy(100);
    setAD(30);
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
    std::cout << ">>> FragTrap parameterized constructor" << std::endl;
    setName(name);
    setHP(100);
    setEnergy(100);
    setAD(30);
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
    std::cout << ">>> FragTrap copy constructor" << std::endl;
    setName(other.name);
    setHP(other.HP);
    setEnergy(other.Energy);
    setAD(other.AD);
}

FragTrap::~FragTrap()
{
    std::cout << ">>> FragTrap default destructor" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
    std::cout << ">>> FragTrap assignment operator overload" << std::endl;
    if (this != &other)
    {
        name = other.name;
        HP = other.HP;
        Energy = other.Energy;
        AD = other.AD;
    }
    return *this;
}

void FragTrap::attack(const std::string &target)
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
    std::cout << "FragTrap " << getName()
              << " attacks " << target << ", causing "
              << getAD() << " points of damage" << std::endl;
}

void FragTrap::takeDamage(unsigned int amount)
{
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
    std::cout << "FragTrap " << getName()
              << " takes " << amount << " points of damage" << std::endl;
}

void FragTrap::beRepaired(unsigned int amount)
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
    if (amount > __INT_MAX__ || (int)amount > __INT_MAX__ - getHP())
    {
        std::cout << getName() << ": unsafe operation" << std::endl;
        return;
    }
    setHP(getHP() + amount);
    setEnergy(getEnergy() - 1);
    std::cout << "FragTrap " << getName()
              << " is repaired by " << amount << " hit points" << std::endl;
}

void FragTrap::highFivesGuys()
{
    std::cout << "FragTrap: high five!" << std::endl;
}
