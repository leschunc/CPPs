#include "Fixed.hpp"
#include <iostream>

void disp(Fixed result)
{
    std::cout << result << std::endl;
}

void say(std::string str)
{
    std::cout << str << std::endl;
}

void sum(Fixed a, Fixed b)
{
    disp(a + b);
}

void sub(Fixed a, Fixed b)
{
    disp(a - b);
}

void preIncrement(Fixed a)
{
    disp(a);
    disp(++a);
}

void postIncrement(Fixed a)
{
    disp(a++);
    disp(a);
}

void preDecrement(Fixed a)
{
    disp(a);
    disp(--a);
}

void postDecrement(Fixed a)
{
    disp(a--);
    disp(a);
}

void less(Fixed a, Fixed b)
{
    if (a < b)
        say("a < b");
    else
        say("a is not < b");
}

void more(Fixed a, Fixed b)
{
    if (a > b)
        say("a > b");
    else
        say("a is not > b");
}

void lessEqual(Fixed a, Fixed b)
{
    if (a <= b)
        say("a <= b");
    else
        say("a is not <= b");
}

void moreEqual(Fixed a, Fixed b)
{
    if (a >= b)
        say("a >= b");
    else
        say("a is not >= b");
}

void equal(Fixed a, Fixed b)
{
    if (a == b)
        say("a == b");
    else
        say("a is not == b");
}

void diff(Fixed a, Fixed b)
{
    if (a != b)
        say("a != b");
    else
        say("a is not != b");
}

void batchTest()
{
    Fixed a;
    Fixed b;

    sum(a, b);
    sub(a, b);
    less(a, b);
    more(a, b);
    lessEqual(a, b);
    moreEqual(a, b);
    equal(a, b);
    diff(a, b);

    preIncrement(a);
    postIncrement(a);
    preDecrement(a);
    postDecrement(a);
}

int main(void)
{
    batchTest();    

    return 0;
}
    