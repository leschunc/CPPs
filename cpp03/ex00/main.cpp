#include "ClapTrap.hpp"

void overflowProtecDemo()
{
    ClapTrap ct("Claudia");

    ct.beRepaired(0x7fffffed);
    for (size_t i = 0; i < 10; i++)
    {
        ct.beRepaired(1);
    }
    ct.beRepaired(1);
}

int main()
{
    // overflowProtecDemo();

    ClapTrap a("Roberta");

    for (size_t i = 0; i < 11; i++)
        a.attack("this other gay");
    
    a.beRepaired(2);

    ClapTrap b("Claudia");
    for (size_t i = 0; i < 5; i++)
    {
        b.beRepaired(1);
        b.takeDamage(4);
    }

    return 0;
}
