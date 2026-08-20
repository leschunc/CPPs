#include "Fixed.hpp"
#include <iostream>

void batchTest()
{
    Fixed a((float)20.6);
    Fixed b((float)20.5);
    Fixed c((float)20.5);

    std::cout << "a " << a << std::endl << "b " << b << std::endl << "c " << c << std::endl << std::endl;

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
        std::cout << "a == c" << std::endl;
    if (b != c)
        std::cout << "b != c" << std::endl;
    std::cout << std::endl;
}

int main(void)
{
    // batchTest();

    Fixed a(10.0f);
    Fixed b(0.0f);

    // float zero = 1/0;

    // (void)zero;

    std::cout << 0.0f / 0.0f << std::endl;

    return 0;
}
