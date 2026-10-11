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
    if (isprint(arg.at(0)))
        std::cout << "char:\t[" << static_cast<char>(arg.at(0)) << "]\n";
    else
        std::cout << "char:\t[non-displayable]\n";

    std::cout << "int:\t[" << static_cast<int>(arg.at(0)) << "]\n";
    std::cout << "float:\t[" << static_cast<float>(arg.at(0)) << "f]\n";
    std::cout << "double:\t[" << static_cast<double>(arg.at(0)) << "]\n";
}

void ScalarConverter::multiple(const std::string &arg)
{
    double num;
    char* end;
    
    num = std::strtod(arg.c_str(), &end);
    if (end == arg.c_str())
    {
        std::cout << "This is not a parseable string to a number\n";
        return ;
    }
    if (isprint(static_cast<char>(num)))
        std::cout << "char:\t[" << static_cast<char>(num) << "]\n";
    else
        std::cout << "char:\t[non-displayable]\n";

    std::cout << "int:\t[" << static_cast<int>(num) << "]\n";
    std::cout << "float:\t[" << static_cast<float>(num) << "f]\n";
    std::cout << "double:\t[" << static_cast<double>(num) << "]\n";
}

void ScalarConverter::convert(const std::string &arg)
{
    if (arg.size() == 1)
        single(arg);
    else
        multiple(arg);
}
