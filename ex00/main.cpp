#include "Zombie.cpp"
#include "randomChump.cpp"
#include "newZombie.cpp"

int main()
{
    Zombie *zPointer = newZombie("jesus");
    zPointer->announce();
    randomChump("cristiano");
    return 0;
}
