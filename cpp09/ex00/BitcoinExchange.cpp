#include "BitcoinExchange.hpp"
// #include "Split.hpp"
// #include

typedef std::pair<std::string, std::string> StrPair;
typedef std::map<std::string, std::string>::iterator MapIt;

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

void BitcoinExchange::checkDate(const std::string &date)
{
	std::string err = "Invalid ISO format \"" + date + "\"\n";

	if (date.size() != 10)
		throw std::runtime_error(err.c_str());
	for (size_t i = 0; i != date.size(); i++)
	{
		if (i == 4 || i == 7)
		{
			if (date.at(i) != '-')
				throw std::runtime_error(err.c_str());
		}
		else if (isdigit(date.at(i)) == false)
			throw std::runtime_error(err.c_str());
	}
}

void BitcoinExchange::checkRate(const std::string &rate)
{
	(void)rate;
}

// void BitcoinExchange::checkValues()
// {
// 	StrPair pair;

// 	for (MapIt it = valueByDate.begin(); it != valueByDate.end(); it++)
// 	{
// 		try
// 		{
// 			checkDate((*it).first);
// 			checkRate((*it).second);
// 		}
// 		catch (const std::exception &e)
// 		{
// 			valueByDate
// 		}
// 	}
// }

// TODO: try and catch outside
void BitcoinExchange::loadMap(const std::string &line, char c)
{
	if (line.empty())
		throw std::runtime_error("Invalid empty line in .csv file\n");

	std::string date;
	std::string rate;

	size_t index = line.find(c);
	date = trimSpaces(line.substr(0, index));
	size_t start = index + 1;
	index = line.find(c, index);
	rate = trimSpaces(line.substr(start, index));
	checkDate(date);
	checkRate(rate);
	if (valueByDate.insert(StrPair(date, rate)).second == false)
	{
		std::string err = "Possible duplicated line: " + line + '\n';
		throw std::runtime_error(err.c_str());
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
		try
		{
			loadMap(line, ',');
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what();
		}
	}
}

void BitcoinExchange::dbShowMap()
{
	for (MapIt it = valueByDate.begin(); it != valueByDate.end(); it++)
	{
		std::cout << (*it).first << " " << (*it).second << "\n";
	}
}
