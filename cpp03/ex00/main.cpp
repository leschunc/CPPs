#include "ClapTrap.hpp"

int main()
{

    ClapTrap mario("mario");

    for (size_t i = 0; i < 20; i++)
    {
        mario.attack("leonan");
    }

    return 0;
}
