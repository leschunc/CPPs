#include <iostream>
#include <string>
#include <fstream>

// std::string replace(std::string line, std::string toFind, std::string replaceStr)
// {
//     std::string newStr;
//     (void)replaceStr;
//     newStr = line.at(line.find(toFind));
//     while (1)
//     {
//         size_t pos = newStr.find(toFind);
//         if (pos == std::string::npos)
//             break;
//         newStr = newStr.substr(0, std::string::npos);
//         std::cout << newStr;
//     }
//     return "hello";
// }

// int main(int argc, char const *argv[])
// {
//     if (argc != 4)
//         return 1;

//     std::fstream filestream(argv[1]);
//     std::string s1 = argv[2];
//     std::string s2 = argv[3];
//     std::string buffer;
//     std::string newFile = (std::string(argv[1]) + ".append");
//     std::string join;

//     while (std::getline(filestream, buffer))
//     {
//         join += replace(buffer, s1, s2) += "\n";
//     }
//     std::ofstream output(newFile.c_str());
//     output << join;
//     return 0;
// }

int main(int argc, const char **argv)
{
    if (argc != 4)
        return 1;
    std::string line = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    size_t match;
    size_t start;

    std::string result;

    match = 0;
    start = 0;
    while (1)
    {
        match = line.find(s1);
        if (match == std::string::npos)
            break ;
        result += line.substr(start, match);
        result += s2;
        if (match + s1.size() > line.size())
            break;
        line = line.substr(match + s1.size());
    }
    result += line.substr(start, match);
    std::cout << result << std::endl;
    return 0;
}
