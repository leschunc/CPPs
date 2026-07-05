#include <iostream>
#include <string>
#include <fstream>

int main(int argc, char const *argv[])
{
    if (argc != 4)
        return 1;
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    std::string buffer;
    std::fstream filestream(argv[1]);
    std::string filename = (std::string(argv[1]) + ".append");
    std::string join;
    std::ofstream output(filename.c_str());
    
    while (std::getline(filestream, buffer))
    {
        join += buffer += "\n";
    }

    std::cout << join;

    return 0;
}
