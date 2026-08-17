#ifndef PHONEBOOK
#define PHONEBOOK

#include "contact.hpp"

class PhoneBook
{
private:
    Contact contacts[8];

public:
    PhoneBook();
    ~PhoneBook();
    void start();
    void add();
    void search();
};
#endif