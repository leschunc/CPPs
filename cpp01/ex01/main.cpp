#include "Zombie.hpp"

int main()
{
    Zombie *horde;
    horde = zombieHorde(20, "seila");
    if (!horde)
        return 1;    
    delete [] horde;
    return 0;
}
