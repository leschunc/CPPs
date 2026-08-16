#include "Zombie.hpp"

int main()
{
    Zombie *horde;

    horde = zombieHorde(20, "seilas");
    
    delete [] horde;
    return 0;
}
