#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#define BIGBRAIN 100
#define DEBUG false

class Brain
{
private:
    std::string *ideas;

public:
    Brain();
    Brain(const Brain &copy);
    ~Brain();

    Brain &operator=(const Brain &copy);
};

#endif