#ifndef CLAPTRAP
#define CLAPTRAP

class ClapTrap
{
private:
    int HP;
    int Energy;
    int AD;

public:
    ClapTrap();
    ClapTrap(const ClapTrap &other);
    ~ClapTrap();
    ClapTrap &operator=(ClapTrap &other);
};

#endif