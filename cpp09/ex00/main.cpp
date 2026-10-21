#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
// #include <cfcntl>
#include <exception>

template <typename T>
void print(T toStr)
{
	std::cout << toStr;
}

void argCheck(int ac, char *av[])
{
	if (ac < 2)
		throw std::logic_error("no arguments");

	std::string fileName(av[1]);

	std::string ext = fileName.substr(fileName.find('.'));

	if (ext.compare(".csv") != 0)
		throw std::runtime_error("wrong file extension");
}

int main(int ac, char *av[])
{

	argCheck(ac, av);

	std::fstream csv(av[1]);

	if (csv.good() == false)
	{
		// sayError("Bad file is not good\n");
		return 0;
	}

	

	




	// std::string str;
	// std::getline(file, str);
	// putn(str);

	return 0;
}
