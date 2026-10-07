#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cctype>

class ScalarConverter
{
private:
    static void single(const std::string &arg);
    static void multiple(const std::string &arg);

public:
    ScalarConverter();
    ScalarConverter(const ScalarConverter &copy);
    ~ScalarConverter();

    const ScalarConverter &operator=(const ScalarConverter &copy);

    static void convert(const std::string &arg);
};

#endif