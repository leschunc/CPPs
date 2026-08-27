#include "Brain.hpp"

Brain::Brain()
{
    ideas = new std::string[BIGBRAIN];
    std::cout << ">>>>>>> Brain default constructor " << std::endl;
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
    std::cout << ">>>>>>> Brain default destructor " << std::endl;
    delete[] ideas;
}

void Brain::setThought(const std::string &thought, int no)
{
    if (no >= 0 && no < BIGBRAIN)
        ideas[no] = thought;
}

const std::string &Brain::getThought(int no) const
{
    static const std::string empty = "";

    if (no >= 0 && no < BIGBRAIN)
        return ideas[no];
    return (empty);
}
