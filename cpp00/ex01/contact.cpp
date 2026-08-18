#include "contact.hpp"

Contact::Contact(void)
{
    this->filled = false;
}
Contact::~Contact(void)
{
}

std::string Contact::getFirstName()
{
    return (this->firstName);
}
std::string Contact::getLastName()
{
    return (this->lastName);
}
std::string Contact::getNickName()
{
    return (this->nickName);
}
std::string Contact::getPhoneNumber()
{
    return (this->phoneNumber);
}
std::string Contact::getDarkestSecret()
{
    return (this->darkestSecret);
}

void Contact::setFirstName(std::string input)
{
    this->firstName = input;
}
void Contact::setLastName(std::string input)
{
    this->lastName = input;
}
void Contact::setNickName(std::string input)
{
    this->nickName = input;
}
void Contact::setPhoneNumber(std::string input)
{
    this->phoneNumber = input;
}
void Contact::setDarkestSecret(std::string input)
{
    this->darkestSecret = input;
}

bool Contact::isEmpty()
{
    return (!this->filled);
}

void Contact::setUsed()
{
    this->filled = true;
}
