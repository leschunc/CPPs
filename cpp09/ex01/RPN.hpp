#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <exception>
#include <algorithm>

using std::cout;

class RPN
{
private:
    std::stack<char> tokens;

public:
    RPN();
    RPN(int ac, char *av[]);
    RPN(const RPN &ref);
    RPN &operator=(const RPN &ref);
    ~RPN();

    void processLine(std::string line);
    void addElement(char c);
    void dispStack();

    void calculate();

    class parse_error : public std::runtime_error
    {
    public:
        parse_error(const std::string &what_arg) : std::runtime_error(what_arg) {}
    };
    class exec_error : public std::logic_error
    {
    public:
        exec_error(const std::string &what_arg) : std::logic_error(what_arg) {}
    };
};

#endif