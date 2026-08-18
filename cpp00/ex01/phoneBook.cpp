#include "phoneBook.hpp"

PhoneBook::PhoneBook()
{
}
PhoneBook::~PhoneBook()
{
}

void PhoneBook::start()
{
    std::string input;

    while (1)
    {
        if (std::cin.eof())
            break;
        std::cout << "Enter command: " << std::endl;
        std::getline(std::cin, input);
        if (input.compare("ADD") == 0)
            this->add();
        if (input.compare("SEARCH") == 0)
            this->search();
        if (input.compare("EXIT") == 0)
            break;
    }
}

void PhoneBook::add()
{
    static int i = 0;

    std::string input;

    std::cout << "Enter first name: " << std::endl;
    std::getline(std::cin, input);
    if (std::cin.eof())
        return;
    this->contacts[i].setFirstName(input);
    std::cout << "Enter last name: " << std::endl;
    std::getline(std::cin, input);
    if (std::cin.eof())
        return;
    this->contacts[i].setLastName(input);
    std::cout << "Enter nickname: " << std::endl;
    std::getline(std::cin, input);
    if (std::cin.eof())
        return;
    this->contacts[i].setNickName(input);
    std::cout << "Enter phone number: " << std::endl;
    std::getline(std::cin, input);
    if (std::cin.eof())
        return;
    this->contacts[i].setPhoneNumber(input);
    std::cout << "Enter darkest secret: " << std::endl;
    std::getline(std::cin, input);
    if (std::cin.eof())
        return;
    this->contacts[i].setDarkestSecret(input);
    this->contacts[i].setUsed();
    i = (i + 1) % SIZE;
}

void PhoneBook::dispFormat(std::string str, int type)
{
    if (str.size() > 9)
        str = str.substr(0, 9) + ".";
    std::cout << std::setw(10) << std::right << str;
    if (type)
        std::cout << std::endl;
    else
        std::cout << "|";
}

void PhoneBook::listContacts()
{
    for (int i = 0; i < SIZE; i++)
    {
        std::ostringstream ss;
        ss << i;
        if (this->contacts[i].isEmpty())
            break;
        dispFormat(ss.str(), 0);
        dispFormat(this->contacts[i].getFirstName(), 0);
        dispFormat(this->contacts[i].getLastName(), 0);
        dispFormat(this->contacts[i].getNickName(), 1);
    }
}

void PhoneBook::dispContact(int num)
{
    std::cout << "Name: " << contacts[num].getFirstName() << std::endl;
    std::cout << "Last name: " << contacts[num].getLastName() << std::endl;
    std::cout << "Nickname: " << contacts[num].getNickName() << std::endl;
    std::cout << "Phone no.: " << contacts[num].getPhoneNumber() << std::endl;
    std::cout << "Darkest secret: " << contacts[num].getDarkestSecret() << std::endl;
}

void PhoneBook::promptIndex()
{
    std::string input;
    int num;
    while (1)
    {
        std::cout << "Insert index:" << std::endl;
        std::getline(std::cin, input);
        if (input.empty())
            break;
        num = atoi(input.c_str());
        if (num >= 0 and num < SIZE and contacts[num].isEmpty() == false)
            dispContact(num);
        else
        {
            std::cout << "nope, invalid index" << std::endl;
            continue;
        }
    }
}

void PhoneBook::search()
{
    listContacts();
    promptIndex();
}
