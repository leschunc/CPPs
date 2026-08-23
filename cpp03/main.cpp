#include "ClapTrap.hpp"

void overflowProtecDemo()
{
    ClapTrap ct;

    ct.beRepaired(0x7fffffed);
    for (size_t i = 0; i < 10; i++)
    {
        ct.beRepaired(1);
    }
    ct.beRepaired(1);
}

void status(ClapTrap ct)
{
    sayNum(ct.getHP());
    sayNum(ct.getEnergy());
    sayNum(ct.getAD());
    say("");
}

int main()
{
    overflowProtecDemo();

    ClapTrap a;

    status(a);

    return 0;
}
