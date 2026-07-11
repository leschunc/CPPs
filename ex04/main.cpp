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

int main()
{
    std::string line = "this is a this is aa and this is aaa";
    std::string toReplace = "aa";
    std::string replaceWith = "bbbbb";
    size_t match;
    size_t start;

    std::string result;

    match = 0;
    start = 0;
    while (1)
    {
        match = line.find(toReplace);
        if (match == std::string::npos)
            break ;
        result += line.substr(start, match);
        result += replaceWith;
        if (match + toReplace.size() > line.size())
            break;
        line = line.substr(match + toReplace.size());
    }
    std::cout << result << std::endl;

    return 0;
}
