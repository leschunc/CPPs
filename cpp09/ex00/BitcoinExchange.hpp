#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>

using std::cerr;
using std::cout;

typedef std::pair<std::string, std::string> StrPair;
typedef std::map<std::string, std::string>::iterator MapIt;

class BitcoinExchange
{
private:
    std::ifstream file;
    std::map<std::string, std::string> valueByDate;
    BitcoinExchange(const BitcoinExchange &ref);
    BitcoinExchange &operator=(const BitcoinExchange &ref);

public:
    // TODO: OCF is not defined
    // OCF
    BitcoinExchange();
    ~BitcoinExchange();

    // files
    void openFileCheck(int ac, char *av[]);
    void loadFileCheck();

    // loading
    void loadMap(const std::string &str);

    // parsing
    std::string trimSpaces(const std::string &str);
    void dateFormatCheck(const std::string &date);
    bool isLeap(int year);
    void checkDate(const std::string &date);
    void checkRate(const std::string &rate);
    void checkValue(const std::string &value);

    // input loop
    void readInput();
    void validateInput(const std::string &line);
    void findEntry(const StrPair &p);
    void printInput(const MapIt& it, const StrPair &p);

    // throw wrapper
    void rtDateErr(const std::string &date);
    void rtFormatErr(const std::string &date);

    // debug
    void dbShowMap();

    class parse_error : public std::runtime_error
    {
    public:
        parse_error(const std::string &what_arg) : std::runtime_error(what_arg)
        {
        }
    };
};

#endif
