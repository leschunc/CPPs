#include "phoneBook.hpp"

PhoneBook::PhoneBook() {}
PhoneBook::~PhoneBook() {}
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
        return ;
    this->contacts[i].setFirstName(input);
    std::cout << "Enter last name: " << std::endl;
    std::getline(std::cin, input);
    if (std::cin.eof())
        return ;
    this->contacts[i].setLastName(input);
    std::cout << "Enter nickname: " << std::endl;
    std::getline(std::cin, input);
    if (std::cin.eof())
        return ;
    this->contacts[i].setNickName(input);
    std::cout << "Enter phone number: " << std::endl;
    std::getline(std::cin, input);
    if (std::cin.eof())
        return ;
    this->contacts[i].setPhoneNumber(input);
    std::cout << "Enter darkest secret: " << std::endl;
    std::getline(std::cin, input);
    if (std::cin.eof())
        return ;
    this->contacts[i].setDarkestSecret(input);
    i = (i + 1) % 8;
}

void PhoneBook::search()
{
    for (int i = 0; i < 8; i++)
    {
        std::cout << this->contacts[i].getFirstName() << std::endl;
        std::cout << this->contacts[i].getLastName() << std::endl;
        std::cout << this->contacts[i].getNickName() << std::endl;
        std::cout << this->contacts[i].getPhoneNumber() << std::endl;
        std::cout << this->contacts[i].getDarkestSecret() << std::endl;
    }
}
