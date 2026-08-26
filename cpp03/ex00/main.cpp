#include "ClapTrap.hpp"

void trio()
{
    ClapTrap mario("mario");
    mario.attack("charlie");

    ClapTrap charlie;
    charlie.setName("charlie");
    charlie.attack("malory");

    {
        ClapTrap malory(mario);
        malory.setName("malory");
        malory.attack("amy");
    }

    ClapTrap amy;
    amy = charlie;
    amy.setName("amy");
    amy.attack("mario");
}

void exhaust()
{
    ClapTrap antonio("tonyo");

    for (size_t i = 0; i < 11; i++)
        antonio.attack("no one");

    for (size_t i = 0; i < 3; i++)
        antonio.beRepaired(7);

    for (size_t i = 0; i < 11; i++)
        antonio.takeDamage(2);
}

void scope()
{
    ClapTrap a("a");

    {
        ClapTrap b("b");
        b.attack("a");
    }

    a.attack("b");
}

int main()
{

    // trio();

    exhaust();

    // scope();

    return 0;
}
