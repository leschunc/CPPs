#include "ClapTrap.hpp"

int main()
{
    ClapTrap hello;
    ClapTrap world(hello);
    hello = world;
    hello.setAD(world.getAD());
    return 0;
}
