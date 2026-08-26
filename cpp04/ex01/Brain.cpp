#include "Brain.hpp"

Brain::Brain()
{
    std::cout << ">>>>>>> Brain default constructor" << std::endl;
    ideas = new std::string[BIGBRAIN];
}

Brain::Brain(const Brain &copy)
{
    std::cout << ">>>>>>> Brain copy constructor" << std::endl;
    ideas = new std::string[BIGBRAIN];
    for (size_t i = 0; i < BIGBRAIN; i++)
    {
        ideas[i] = copy.ideas[i];
    }
}

Brain &Brain::operator=(const Brain &copy)
{
    std::cout << ">>>>>>> Brain assignment operator overload" << std::endl;
    if (this == &copy)
        return *this;
    for (size_t i = 0; i < BIGBRAIN; i++)
    {
        ideas[i] = copy.ideas[i];
    }
    return *this;
}

Brain::~Brain()
{
    std::cout << ">>>>>>> Brain default destructor" << std::endl;
    delete[] ideas;
}
