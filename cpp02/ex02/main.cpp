#include "Fixed.hpp"
#include <iostream>

void batchTest()
{
    Fixed a((float)0.0f);
    Fixed b((float)0.0f);
    Fixed c((float)0.1f);

    std::cout << "a " << a << std::endl
              << "b " << b << std::endl
              << "c " << c << std::endl
              << std::endl;

    if (a > b)
        std::cout << "a > b" << std::endl;
    if (a < b)
        std::cout << std::endl;
    std::cout << std::endl;
    if (b >= c)
        std::cout << "b >= c" << std::endl;
    if (b <= c)
        std::cout << std::endl;
    std::cout << std::endl;
    if (a == b)
        std::cout << "a == b" << std::endl;
    if (b != c)
        std::cout << "b != c" << std::endl;
    std::cout << std::endl;

    std::cout << "post decrement a ";
    float d = (a--).toFloat();
    std::cout << d << std::endl;

    std::cout << "pre decrement a ";
    d = (--a).toFloat();
    std::cout << d << std::endl;

    std::cout << "post increment a ";
    d = (a++).toFloat();
    std::cout << d << std::endl;

    std::cout << "pre increment a ";
    d = (++a).toFloat();
    std::cout << d << std::endl;
}

int main(void)
{
    batchTest();

    return 0;
}
