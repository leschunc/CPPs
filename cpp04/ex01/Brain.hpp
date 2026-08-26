#ifndef BRAIN
#define BRAIN

#include <iostream>
#define BIGBRAIN 100

class Brain
{
private:
    std::string *ideas;

public:
    Brain();
    Brain(const Brain &copy);
    ~Brain();

    Brain &Brain::operator=(const Brain &copy);
};

#endif