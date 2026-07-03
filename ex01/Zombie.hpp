#include <string>
#include <iostream>

class Zombie
{
private:
    std::string name;

public:
    Zombie();
    Zombie(std::string name);
    Zombie(int N);
    void setName(std::string name);
    void announce(void);
    ~Zombie();
};
