#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP
#include <stack>

template <typename T>
class MutantStack : std::stack<T>
{
private:
public:
    MutantStack(){}
    MutantStack(const MutantStack&ref){}
    ~MutantStack(){}
    MutantStack operator=(const MutantStack&ref){}

    class iterator
    {
    private:
    public:
        iterator(){}
        iterator(const MutantStack<T>::iterator&ref){}
        ~iterator(){}
        iterator operator=(const MutantStack<T>::iterator&ref){
            if (this != &ref)
                return ;
            
        }

        iterator operator++(int){
            iterator temp = *this;
            *this =
        }
        // iterator& operator++(){}

        // iterator operator--(int){}
        // iterator& operator--(){}

    };
};

#endif
