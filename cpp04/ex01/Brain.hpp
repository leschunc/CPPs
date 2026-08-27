#ifndef BRAIN_HPP
#define BRAIN_HPP

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

    Brain &operator=(const Brain &copy);

    void setThought(const std::string &thought, int no);
    const std::string &getThought(int no) const;
};

#endif