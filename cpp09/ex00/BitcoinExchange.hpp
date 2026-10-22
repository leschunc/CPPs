#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <exception>
#include <map>
#include <set>

using std::cerr;
using std::cout;

class BitcoinExchange
{
private:
    std::ifstream file;
    std::map<std::string, std::string> valueByDate;
    BitcoinExchange(const BitcoinExchange &ref);
    BitcoinExchange &operator=(const BitcoinExchange &ref);

public:
    BitcoinExchange();
    ~BitcoinExchange();

    void openFileCheck(int ac, char *av[]);
    void loadFileCheck();
    void loadMap(const std::string &str, char c);
    std::string trimSpaces(const std::string &str);
    void checkValue(const std::string &value);
    
    void dbShowMap();
};

#endif
