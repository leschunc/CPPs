#include "Fixed.hpp"
#include <iostream>

int main()
{
    Fixed num = 9;
    Fixed num2;
    
    std::cout << num2.getRawBits() << std::endl;
    num2 = num;
    std::cout << num2.getRawBits() << std::endl;
    num2.setRawBits(3);
    std::cout << num2.getRawBits() << std::endl;
    return 0;
}
