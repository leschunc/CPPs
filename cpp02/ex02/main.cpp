/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leschunc <leschunc@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 22:20:24 by leschunc          #+#    #+#             */
/*   Updated: 2026/08/21 22:22:35 by leschunc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
    say("sum");
    disp(a + b);
}

void sub(Fixed a, Fixed b)
{
    say("sub");
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

void mult(Fixed a, Fixed b)
{
    say("a * b");
    disp(a * b);
}

void div(Fixed a, Fixed b)
{
    say("a / b");
    disp(a / b);
}

void min(Fixed a, Fixed b)
{
    say("min: a b");
    disp(Fixed::min(a, b));
}

void max(Fixed a, Fixed b)
{
    say("max: a b");
    disp(Fixed::max(a, b));
}

void batchTest()
{
    Fixed a(7.0f);
    Fixed b(3.0f);

    std::cout << a << " " << b << std::endl;

    sum(a, b);
    sub(a, b);
    mult(a, b);
    div(a, b);
    less(a, b);
    more(a, b);
    lessEqual(a, b);
    moreEqual(a, b);
    equal(a, b);
    diff(a, b);
    min(a, b);
    max(a, b);

    preIncrement(a);
    postIncrement(a);
    preDecrement(a);
    postDecrement(a);
}

int main(void)
{
    // batchTest();

    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max(a, b) << std::endl;

    return 0;
}
