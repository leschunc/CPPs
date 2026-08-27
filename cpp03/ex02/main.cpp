#include "FragTrap.hpp"
#include "ScavTrap.hpp"

void say(const std::string &anything)
{
    std::cout << anything << std::endl;
}

void scopeTest()
{
    FragTrap a;
    say("before b");
    {
        FragTrap b;
    }
    say("after b");
}

void constructorTest()
{
    FragTrap a;
    FragTrap b(a);
    FragTrap c = a;
    FragTrap d;
    d = a;
    FragTrap e("e");
}

void inheriranceTest()
{

    FragTrap a;

    a.setName("miguel");

    std::cout << a.getName() << std::endl;
}

void individualityTest()
{
    ScavTrap a("ScavTrap");
    a.guardGate();
    FragTrap b("FragTrap");
    b.highFivesGuys();
}

void overFlowTest()
{
    FragTrap a;

    a.takeDamage(-1);
}

int main()
{

    scopeTest();

    constructorTest();

    inheriranceTest();

    individualityTest();

    overFlowTest();

    return 0;
}
