#include "ClapTrap.hpp"

void huh()
{
    ClapTrap ct;

    ct.beRepaired(0x7fffffed);
    for (size_t i = 0; i < 10; i++)
    {
        ct.beRepaired(1);
    }
    ct.beRepaired(1);
}

int main()
{
    huh();

    return 0;
}
