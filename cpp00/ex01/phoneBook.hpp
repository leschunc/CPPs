#ifndef PHONEBOOK
#define PHONEBOOK

#include <iomanip>
#include <sstream>
#include <cstdlib>
#include "contact.hpp"

#define SIZE 8

class PhoneBook
{
private:
    Contact contacts[SIZE];
    void add();
    void search();
    void dispFormat(std::string str, int type);
    void listContacts();
    void promptIndex();
    void dispContact(int num);

public:
    PhoneBook();
    void start();
    ~PhoneBook();
};
#endif