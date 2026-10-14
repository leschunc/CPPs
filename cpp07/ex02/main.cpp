#include <iostream>
#include "Array.hpp"

int main()
{
    Array<char> string(11);

    for (size_t i = 0; i < string.size(); i++)
        string[i] = "hello world"[i];

    for (size_t i = 0; i < string.size(); i++)
        std::cout << string[i];
    
    std::cout << std::endl;

    return 0;
}
