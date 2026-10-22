#include "BitcoinExchange.hpp"
// #include "Split.hpp"

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
		throw std::logic_error("Invalid number of arguments\n");

	std::string fileName(av[1]);
	std::size_t index = fileName.find('.');
	if (index == fileName.npos)
		throw std::runtime_error("Invalid file extension\n");

	std::string ext;
	ext = fileName.substr(index);
	if (ext.compare(".csv") != 0)
		throw std::runtime_error("Invalid file extension\n");

	file.open(av[1], std::ios::in);
	if (file.good() == false)
		throw std::runtime_error("Invalid file state\n");
}

std::string BitcoinExchange::trimSpaces(const std::string &str)
{
	size_t start = str.find_first_not_of("\x9\x20");
	size_t end = str.find_first_of("\x9\x20", start);

	std::string res = str.substr(start, end - start);
	// std::cerr << "Invalid ISO format: try 'YYYY-MM-DD'\n";

	// std::cout << "[" << res << "]\n";
	return res;
}

void BitcoinExchange::checkValue(const std::string &value)
{
	for (size_t i = 0; i != value.size(); i++)
	{
		if (i == 4 || i == 7)
		{
			std::cout << "dash: " << value.at(i) << "\n";
			if (isdigit(value.at(i)) == false)
			{
				// std::cout << "not a digit bro" << std::endl;
				throw std::runtime_error("Invalid ISO format: try 'YYYY-MM-DD'\n");
			}
		}
		else
		{
			std::cout << value.at(i) << " is digit" << "\n";
			if (value.at(i) != '-')
				throw std::runtime_error("Invalid ISO format: try 'YYYY-MM-DD'\n");
		}
	}
}

// TODO: try and catch outside
void BitcoinExchange::checkLines(const std::string &line, char c)
{
	if (line.empty())
		throw std::runtime_error("Invalid empty line in .csv file\n");

	size_t start = 0;
	size_t index = 0;
	std::string date;
	std::string rate;
	// valueByDate.insert()
	while ((index = line.find(c, index)))
	{
		date = trimSpaces(line.substr(start, index));
		index++;
		start = index;
		if (index == 0)
			break;

		index = line.find(c, index);
		rate = trimSpaces(line.substr(start, index));
		index++;
		start = index;

		// valueByDate[date] = rate;
		// if (valueByDate.insert({date, rate}).second == false)
		// 	throw std::runtime_error("Invalid insertion on map\n");

		// checkValue(value);
		if (index == line.npos)
		{
			// std::cout << "\n";
			return;
		}
	}
}

void BitcoinExchange::loadFileCheck()
{
	std::string line;

	// TODO: remove this later
	bool skipFirst = true;

	while (getline(file, line))
	{
		if (skipFirst)
		{
			skipFirst = false;
			continue;
		}
		checkLines(line, ',');
	}
}
