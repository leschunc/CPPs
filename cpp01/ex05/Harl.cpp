#include "Harl.hpp"

Harl::Harl()
{
}
Harl::~Harl()
{
}

void Harl::debug(void)
{
    std::cout << "I debug" << std::endl;
}
void Harl::info(void)
{
    std::cout << "I inform" << std::endl;
}
void Harl::warning(void)
{
    std::cout << "I I warn" << std::endl;
}
void Harl::error(void)
{
    std::cout << "I error" << std::endl;
}

void Harl::complain(std::string level)
{
    int option = -1;
    std::string arr[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    for (size_t i = 0; i < 4; i++)
    {
        if (level == arr[i])
        {
            option = i;
            break;
        }
    }
    void (Harl::*fun[4])() =
        {
            &Harl::debug,
            &Harl::info,
            &Harl::warning,
            &Harl::error
        };
    if (option != -1)
        (this->*fun[option])();
}
