#include "Zombie.hpp"

int main()
{
    Zombie *zPointer = newZombie("Jesus");
    zPointer->announce();
    randomChump("Cristiano");
    Zombie amanda("Amanda");
    amanda.announce();
    delete zPointer;
    return 0;
}
