#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &ref)
{
	if (this == &ref)
		return;
}
BitcoinExchange::~BitcoinExchange()
{
}
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &ref)
{
	(void)ref;
	return *this;
}

// TODO: are all checks being performed here
void BitcoinExchange::openFileCheck(int ac, char *av[])
{
	if (ac < 2)
		throw std::logic_error("Wrong number of arguments\n");

	std::string fileName(av[1]);
	std::size_t index = fileName.find('.');
	if (index == fileName.npos)
		throw std::runtime_error("Wrong file extension\n");

	std::string ext;
	ext = fileName.substr(index);
	if (ext.compare(".csv") != 0)
		throw std::runtime_error("Wrong file extension\n");

	file.open(av[1], std::ios::in);
	if (file.good() == false)
		throw std::runtime_error("Wrong file state\n");
}

void BitcoinExchange::loadFileCheck()
{
	
	while ()
	{
		/* code */
	}
}