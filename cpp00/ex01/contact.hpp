#ifndef CONTACT
#define CONTACT
#include <string>
#include <iostream>

class Contact
{
private:
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string phoneNumber;
	std::string darkestSecret;
	bool		filled;

public:
	Contact();
	
	std::string getFirstName();
	std::string getLastName();
	std::string getNickName();
	std::string getPhoneNumber();
	std::string getDarkestSecret();
	bool isEmpty();
	
	void setFirstName(std::string input);
	void setLastName(std::string input);
	void setNickName(std::string input);
	void setPhoneNumber(std::string input);
	void setDarkestSecret(std::string input);
	void setUsed();
	
	~Contact();
};
#endif