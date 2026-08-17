#include <iostream>
#include <cctype>

int main(int argc, char const *argv[])
{
    if (argc < 2)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }
    std::string buf;
    for (int i = 1; i < argc; i++)
    {
        buf = argv[i];
        size_t buflen = buf.size();
        for (size_t j = 0; j < buflen; j++)
        {
            std::cout << static_cast<char>(toupper(argv[i][j]));
        }
    }
    std::cout << std::endl;
    return 0;
}
