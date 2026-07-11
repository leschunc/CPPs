#include <iostream>
#include <string>
#include <fstream>

std::string replace(std::string line, std::string toFind, std::string replaceStr)
{
    std::string newStr;
    (void)line, (void)toFind, (void)replaceStr;
    while (1)
    {
        if (line.find(toFind) != std::string::npos)
        {
            newStr = line.at(line.find(toFind));
            // std::cout << "nope" << std::endl;
            std::cout << line.substr(0, line.find(toFind)) << replaceStr << std::endl;
                        break;

        }
        else
            // std::cout << "replace this " << line.find(toFind) << std::endl;
            continue;
    }
}

int main(int argc, char const *argv[])
{
    if (argc != 4)
        return 1;

    std::fstream filestream(argv[1]);
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    std::string buffer;
    std::string newFile = (std::string(argv[1]) + ".append");
    std::string join;

    while (std::getline(filestream, buffer))
    {
        join += replace(buffer, s1, s2) += "\n";
    }
    std::ofstream output(newFile.c_str());
    output << join;
    return 0;
}
