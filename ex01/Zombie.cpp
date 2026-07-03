#include "Zombie.hpp"

Zombie::Zombie()
{
}

Zombie::Zombie(std::string name)
{
    this->name = name;
}

Zombie::Zombie(int N)
{
    this->name = name;
}

void Zombie::announce(void)
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie()
{
    std::cout << this->name << ": Died!?" << std::endl;
}

void Zombie::setName(std::string name)
{
    this->name = name;
}

Zombie *zombieHorde(int N, std::string name)
{
    Zombie *horde;

    horde = new Zombie[N];

    for (size_t i = 0; i < N; i++)
    {
        horde[i].setName(name);
    }

    return horde;
}
