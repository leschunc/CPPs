#ifndef PHONEBOOK
#define PHONEBOOK

#include <iomanip>
#include <sstream>
#include <cstdlib>
#include "contact.hpp"

#define SIZE 3

class PhoneBook
{
private:
    Contact contacts[SIZE];

public:
    PhoneBook();
    void start();
    void add();
    void search();
    void disp_format(std::string str, int type);
    ~PhoneBook();
};
#endif