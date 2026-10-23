#include "BitcoinExchange.hpp"
#include <cstdlib>

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

bool BitcoinExchange::isLeap(int year)
{
	return (!(year & (year % 25 ? 3 : 15)));
}

void BitcoinExchange::rtFormatErr(const std::string &date)
{
	std::string err = "Invalid ISO format \"" + date + "\"\n";
	throw std::runtime_error(err);
}

void BitcoinExchange::dateFormatCheck(const std::string &date)
{
	if (date.size() != 10)
		rtFormatErr(date);
	for (size_t i = 0; i != date.size(); i++)
	{
		if (i == 4 || i == 7)
		{
			if (date.at(i) != '-')
				rtFormatErr(date);
		}
		else if (isdigit(date.at(i)) == false)
			rtFormatErr(date);
	}
}

void BitcoinExchange::rtDateErr(const std::string &date)
{
	std::string err = "Invalid date \"" + date + "\"\n";
	throw std::runtime_error(err);
}

void BitcoinExchange::checkDate(const std::string &date)
{
	dateFormatCheck(date);

	std::string month = date.substr(5, 2);
	if (month > "12")
		rtDateErr(date);

	std::string day = date.substr(8, 2);
	if (day == "00" || month == "00")
		rtDateErr(date);

	if (month < "08")
	{
		std::string year = date.substr(0, 4);
		if (month == "02" && ((!isLeap(std::atoi(year.c_str())) && day > "28") || day > "29"))
			rtDateErr(date);
		else if (month.at(1) % 2 == 0 && day > "30")
			rtDateErr(date);
		else if (day > "31")
			rtDateErr(date);
	}
	else
	{
		if (month.at(1) % 2 && day > "30")
			rtDateErr(date);
		else if (day > "31")
			rtDateErr(date);
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
	if (index == line.npos)
	{
		std::string err = "Invalid line: " + line + "\n";
		throw std::runtime_error(err);
	}
	date = trimSpaces(line.substr(0, index));
	size_t start = index + 1;
	index = line.find(c, index);
	if (index == line.npos)
	{
		std::string err = "Invalid line: " + line + "\n";
		throw std::runtime_error(err);
	}	
	rate = trimSpaces(line.substr(start, index));
	checkDate(date);
	checkRate(rate);
	if (valueByDate.insert(StrPair(date, rate)).second == false)
	{
		std::string err = "Duplicated date: " + date + ": first entry used\n";
		throw std::runtime_error(err);
	}
}

void BitcoinExchange::loadFileCheck()
{
	std::string line;

	// TODO: should I keep this
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
			std::cerr << "Invalid line: [" + line + "]\n";
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
