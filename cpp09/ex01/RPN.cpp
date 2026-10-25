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
        line = av[1];
        processLine();
    }
    catch (const parse_error &e)
    {
        std::cerr << "Parse error: " << e.what() << '\n';
    }
    catch (const exec_error &e)
    {
        std::cerr << "Exec error: " << e.what() << '\n';
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

// #include <cctype>
// #include <string>

char RPN::popTop()
{
    if (tokens.empty())
        throw parse_error("Unexpected end of expression");
    char c = tokens.top();
    tokens.pop();
    return c;
}

void RPN::calc(char c)
{
    long left = popTop();
    long right = popTop();
    switch (c)
    {
    case '*':
        tokens.push(right * left);
        break;
    case '/':
    {
        if (left == 0)
            throw exec_error("Division by zero");
        tokens.push(right / left);
        break;
    }
    case '+':
        tokens.push(right + left);
        break;
    case '-':
        tokens.push(right - left);
        break;
    }
}

void RPN::pushTokens()
{
    for (size_t i = 0; i < line.size(); i++)
    {
        if (std::isspace(line[i]))
            continue;
        if (std::isdigit(line[i]))
            tokens.push(line[i] - '0');
        else if (std::string("*/+-").find(line[i]) != std::string::npos)
            calc(line[i]);
        else
            throw parse_error("Invalid token");
    }
}

void RPN::processLine()
{
    if (line.empty())
        throw parse_error("Empty line");

    size_t pos = line.find_first_not_of(" ");
    if (pos == line.npos)
        throw parse_error("Unexpected end of expression");

    pushTokens();

    if (tokens.size() > 1)
        throw parse_error("Unexpected end of expression");
    cout << tokens.top() << "\n";
}

void RPN::dispStack()
{

    for (char c; tokens.empty() == false; tokens.pop())
    {
        c = tokens.top();
        cout << c;
    }
}
