#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(const RPN &ref)
{
    (void)ref;
}

RPN &RPN::operator=(const RPN &ref)
{
    (void)ref;
    return *this;
}

RPN::~RPN()
{
}

RPN::RPN(int ac, char *av[])
{

    if (ac != 2)
        return;

    try
    {
        processLine(av[1]);
    }
    catch (const parse_error &e)
    {
        std::cerr << e.what() << '\n';
    }
    catch (const exec_error &e)
    {
        std::cerr << e.what() << '\n';
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

void RPN::processLine(std::string line)
{
    if (line.empty())
        throw parse_error("Empty line");

    std::reverse(line.begin(), line.end());
    for (std::string::iterator it = line.begin(); it != line.end(); it++)
    {
        if (isspace(*it) == false)
            tokens.push(*it);
    }
    dispStack();
    // calculate();
}

void RPN::dispStack()
{

    for (char c; tokens.empty() == false; tokens.pop())
    {
        c = tokens.top();
        cout << c;
    }
}

void RPN::addElement(char c)
{
    (void)c;
}

void RPN::calculate()
{
    long left = tokens.top();
    tokens.pop();

    char operation;
    char right;
    while (tokens.empty() == false)
    {

        operation = tokens.top();
        (void)operation;
        tokens.pop();
        if (tokens.empty())
            throw exec_error("Unexpected end of expression");

        right = tokens.top();
        tokens.pop();

        left = left + right;
    }
    std::cout << left << "\n";
}
