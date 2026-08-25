#include "FragTrap.hpp"
#include "ScavTrap.hpp"

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

    ScavTrap justincase("justin case");

    std::cout << justincase.getName() << std::endl;

    for (size_t i = 0; i < 10; i++)
    {
        a.attack("jurdir birbe");
        std::cout << "CRITOU" << std::endl;
        justincase.takeDamage(8000);
    }
    

    return 0;
}
