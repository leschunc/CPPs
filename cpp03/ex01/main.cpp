#include "ScavTrap.hpp"

int main()
{

    ScavTrap notbatma;

    std::cout << notbatma.getName();

    ScavTrap a("robertinha");

    ScavTrap b(a);

    ScavTrap c = b;

    for (size_t i = 0; i < 11; i++)
    {
        c.attack("juao");
    }

    c.guardGate();

    return 0;
}
