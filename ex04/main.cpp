#include <iostream>
#include <string>
#include <fstream>

std::string findAndReplace(std::string line, std::string s1, std::string s2)
{
    size_t match;
    size_t start;

    std::string result;

    match = 0;
    start = 0;
    while (1)
    {
        match = line.find(s1);
        if (match == std::string::npos)
            break;
        result += line.substr(start, match);
        result += s2;
        if (match + s1.size() > line.size())
            break;
        line = line.substr(match + s1.size());
    }
    result += line.substr(start, match);
    return result;
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
    std::ofstream output(newFile.c_str());

    while (std::getline(filestream, buffer))
        output << findAndReplace(buffer, s1, s2) << std::endl;
    return 0;
}
