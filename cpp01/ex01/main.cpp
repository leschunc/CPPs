#include "Zombie.hpp"

int main()
{
    Zombie *horde;

    horde = zombieHorde(0, "seilas");
    if (!horde)
        return 1;    
    delete [] horde;
    return 0;
}
