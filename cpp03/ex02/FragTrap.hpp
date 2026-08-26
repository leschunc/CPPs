#ifndef FRAGTRAP
#define FRAGTRAP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:
    FragTrap();
    FragTrap(const FragTrap &other);
    FragTrap(const std::string &name);
    ~FragTrap();
    
    FragTrap &operator=(const FragTrap &other);
        
    void attack(const std::string &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

    void highFivesGuys();
};

#endif