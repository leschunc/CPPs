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

    std::cout << a.getName() << std::endl;
}

int main()
{

    // scopeTest();

    constructorTest();

    // inheriranceTest();

    return 0;
}
