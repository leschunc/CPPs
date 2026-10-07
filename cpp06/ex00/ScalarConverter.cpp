#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
    if (this == &copy)
        return;
}

const ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy)
{
    if (this == &copy)
        return (*this);
    return *this;
}

void ScalarConverter::single(const std::string &arg)
{
    if (isalpha(arg.at(0)))
        std::cout << "char:\t[" << static_cast<char>(arg.at(0)) << "]\n";
    else
        std::cout << "char:\t[non-displayable]\n";

    std::cout << "int:\t[" << static_cast<int>(arg.at(0)) << "]\n";
    std::cout << "float:\t[" << static_cast<float>(arg.at(0)) << "]\n";
    std::cout << "double:\t[" << static_cast<double>(arg.at(0)) << "]\n";
}

void ScalarConverter::multiple(const std::string &arg)
{
    double num;

    num = std::strtod(arg.c_str(), 0);

    if (isalpha(static_cast<char>(num)))
        std::cout << "char:\t[" << static_cast<char>(num) << "]\n";
    else
        std::cout << "char:\t[non-displayable]\n";

    std::cout << "int:\t[" << static_cast<int>(num) << "]\n";
    std::cout << "float:\t[" << static_cast<float>(num) << "]\n";
    std::cout << "double:\t[" << static_cast<double>(num) << "]\n";
}

void ScalarConverter::convert(const std::string &arg)
{
    if (arg.size() == 1)
        single(arg);
    else
        multiple(arg);
}
