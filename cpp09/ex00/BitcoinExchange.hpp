#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <exception>
#include <map>

class BitcoinExchange
{
private:
    std::ifstream file;
    std::map<std::string data, std::string value> values;
    BitcoinExchange(const BitcoinExchange &ref);
    BitcoinExchange &operator=(const BitcoinExchange &ref);

public:
    BitcoinExchange();
    ~BitcoinExchange();
    void openFileCheck(int ac, char *av[]);
    void loadFileCheck();
};

#endif
