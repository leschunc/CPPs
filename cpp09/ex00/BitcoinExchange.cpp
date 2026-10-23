#include "BitcoinExchange.hpp"
#include <cstdlib>
#include <climits>

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
		throw parse_error("Invalid number of arguments");

	std::string fileName(av[1]);
	std::size_t index = fileName.find('.');
	if (index == fileName.npos)
		throw parse_error("Invalid file extension");

	std::string ext;
	ext = fileName.substr(index);
	if (ext.compare(".csv") != 0)
		throw parse_error("Invalid file extension");

	file.open(av[1], std::ios::in);
	if (file.good() == false)
		throw parse_error("Invalid file state");
}

std::string BitcoinExchange::trimSpaces(const std::string &str)
{
	size_t start = str.find_first_not_of("\x9\x20");
	size_t end = str.find_last_not_of("\x9\x20");

	std::string res = str.substr(start, end + 1);
	return res;
}

bool BitcoinExchange::isLeap(int year)
{
	return (!(year & (year % 25 ? 3 : 15)));
}

void BitcoinExchange::rtFormatErr(const std::string &date)
{
	std::string err = "Invalid ISO format \"" + date + "\"";
	throw parse_error(err);
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
	std::string err = "Invalid date \"" + date + "\"";
	throw parse_error(err);
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

// int commaCheck(const std::string &rate)
// {
// 	size_t mark = rate.find(',');
// 	if (mark == rate.npos)
// 		return 0;
// 	mark = rate.find(',' );
// }

void BitcoinExchange::checkRate(const std::string &rate)
{
	char *endPtr;
	double num = std::strtod(rate.c_str(), &endPtr);

	if (num > static_cast<double>(INT_MAX))
		throw parse_error("Value too big");

	if (*endPtr != 0)
		throw parse_error("Invalid rate");

	if (rate.find_first_not_of("0123456789.") != rate.npos)
		throw parse_error("Invalid char in rate");
}

void BitcoinExchange::checkValue(const std::string &value)
{
	char *endPtr;
	double num = std::strtod(value.c_str(), &endPtr);

	if (num > static_cast<double>(1000))
		throw parse_error("Value too big");

	if (*endPtr != 0)
		throw parse_error("Invalid value");

	if (value.find_first_not_of("0123456789.") != value.npos)
		throw parse_error("Invalid char in value");
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
void BitcoinExchange::loadMap(const std::string &line)
{
	if (line.empty())
		throw parse_error("Empty entry");

	StrPair p;

	size_t pos = line.find(',');
	if (pos == line.npos)
		throw parse_error("Missing ',' separator: " + line);

	p.first = line.substr(0, pos);
	p.second = line.substr(pos + 1);

	p.first = trimSpaces(p.first);
	p.second = trimSpaces(p.second);

	if (p.first.empty() || p.second.empty())
		throw parse_error("Empty entry: " + line);

	checkDate(p.first);
	checkRate(p.second);

	if (valueByDate.insert(p).second == false)
	{
		throw parse_error("Duplicated date: " + p.first + ": first entry used");
	}
}

void BitcoinExchange::loadFileCheck()
{
	std::string line;

	// TODO: should I keep this
	bool header = true;

	while (getline(file, line))
	{
		if (header)
		{
			header = false;
			if (line.compare("date,exchange_rate") != 0)
				cerr << "Invalid header line\n";
			continue;
		}
		try
		{
			loadMap(line);
		}
		catch (const parse_error &e)
		{
			cerr << e.what() << " on line: [" << line << "]\n";
		}
		catch (const std::exception &e)
		{
			cerr << "Invalid line at: [" << line << "]\n";
		}
	}
	if (valueByDate.empty())
		throw parse_error("Not enough elements in .csv");
}

void BitcoinExchange::dbShowMap()
{
	for (MapIt it = valueByDate.begin(); it != valueByDate.end(); it++)
	{
		cout << (*it).first << " " << (*it).second << "\n";
	}
}

void BitcoinExchange::readInput()
{
	std::string line;

	bool header = true;

	while (std::getline(std::cin, line))
	{
		if (header)
		{
			if (line.compare("date | value") != 0)
				cerr << "Invalid header format\n";
			header = false;
			continue;
		}
		try
		{
			validateInput(line);
		}
		catch (const parse_error &e)
		{
			cerr << e.what() << "\n";
		}
		catch (const std::exception &e)
		{
			cerr << "Invalid input" << '\n';
		}
	}

	// 	file.open(av[1], std::ios::in);
	// if (file.good() == false)
	// 	throw parse_error("Invalid file state");
}

void BitcoinExchange::validateInput(const std::string &line)
{
	std::cout << line << "\n";
	// BitcoinExchange::

	size_t pos = line.find('|');
	if (pos == line.npos)
		throw parse_error("Expected separator '|' not found");

	StrPair p;
	p.first = line.substr(0, pos);
	p.second = line.substr(pos + 1);

	p.first = trimSpaces(p.first);
	p.second = trimSpaces(p.second);
	// checkDate()

	checkDate(p.first);
	checkValue(p.second);

	findEntry(p);
}

void BitcoinExchange::findEntry(const StrPair &p)
{
	MapIt previous;

	// std::cout << p.first << "<<<<<<\n";
	previous = valueByDate.begin();
	for (MapIt it = valueByDate.begin(); it != valueByDate.end(); it++)
	{
		if ((*(it)).first > p.first)
			break;
		previous = it;
	}
	printInput(previous, p);
}

void BitcoinExchange::printInput(const MapIt &it, const StrPair &p)
{
	char *endptr;
	double rate = std::strtod((*it).second.c_str(), &endptr);
	double value = std::strtod(p.second.c_str(), &endptr);

	std::cout << "rate: " << rate << " | value: " << value << " | converted: " << rate * value << "\n";
}
