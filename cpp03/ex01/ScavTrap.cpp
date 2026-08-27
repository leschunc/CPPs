#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    std::cout << ">>> ScavTrap default constructor" << std::endl;
    setName("genericName");
    setHP(100);
    setEnergy(50);
    setAD(20);
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
    std::cout << ">>> ScavTrap parameterized constructor" << std::endl;
    setName(name);
    setHP(100);
    setEnergy(50);
    setAD(20);
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
    std::cout << ">>> ScavTrap copy constructor" << std::endl;
    setName(other.name);
    setHP(other.HP);
    setEnergy(other.Energy);
    setAD(other.AD);
}

ScavTrap::~ScavTrap()
{
    std::cout << ">>> ScavTrap default destructor" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
    std::cout << ">>> ScavTrap assignment operator overload" << std::endl;
    if (this != &other)
    {
        ClapTrap::operator=(other);
    }
    return *this;
}

void ScavTrap::attack(const std::string &target)
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
    std::cout << "ScavTrap " << getName()
              << " attacks " << target << ", causing "
              << getAD() << " points of damage" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}
