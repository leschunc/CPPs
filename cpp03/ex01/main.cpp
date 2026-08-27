#include "ScavTrap.hpp"

void say(const std::string &anything)
{
    std::cout << anything << std::endl;
}

void scopeTest()
{
    ScavTrap a;
    say("before b");
    {
        ScavTrap b;
    }
    say("after b");
}

void constructorTest()
{
    ScavTrap a;
    ScavTrap b(a);
    ScavTrap c = a;
    ScavTrap d;
    d = a;
    ScavTrap e("e");
}

void inheriranceTest()
{

    ScavTrap a;

    a.setName("miguel");
    
    a.attack("outro");

    a.beRepaired(100);

    a.takeDamage(20);
    
}

int main()
{

    scopeTest();

    constructorTest();

    inheriranceTest();

    return 0;
}
