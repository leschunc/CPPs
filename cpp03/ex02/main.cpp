#include "FragTrap.hpp"

int main()
{

    FragTrap a("robertinha");

    FragTrap b(a);

    FragTrap c = b;

    for (size_t i = 0; i < 11; i++)
    {
        c.attack("juao");
    }

    c.highFivesGuys();

    return 0;
}
