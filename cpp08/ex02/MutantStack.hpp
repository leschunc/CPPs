#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
private:
public:
    typedef typename std::stack<T>::container_type::iterator iterator;
    typedef typename std::stack<T>::container_type::const_iterator const_iterator;

    MutantStack() {}
    MutantStack(const MutantStack<T> &ref)
    {
        this->c = ref.c;
    }
    ~MutantStack() {}
    MutantStack operator=(const MutantStack &ref)
    {
        if (this == *ref)
            return;
        this->c = ref.c;
    }

    iterator begin() { return this->c.begin(); }
    iterator end() { return this->c.end(); }
    const_iterator cbegin() { return this->c.begin(); }
    const_iterator cend() { return this->c.end(); }
};

#endif
