#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

void rageQuit(std::string msg)
{
    std::cerr << msg << std::endl;
    std::exit(1);
}

std::string findAndReplace(std::string file, std::string s1, std::string s2)
{
    size_t match;
    size_t start;

    std::string result;

    match = 0;
    start = 0;
    while (1)
    {
        if (s1.empty())
            return file;
        match = file.find(s1);
        if (match == std::string::npos)
            break;
        result += file.substr(start, match);
        result += s2;
        if (match + s1.size() > file.size())
            break;
        file = file.substr(match + s1.size());
    }
    result += file.substr(start, match);
    return result;
}

int main(int argc, char const *argv[])
{
    if (argc != 4)
        rageQuit("Three arguments required");

    std::ifstream inFile(argv[1]);
    if (inFile.good() == false)
        rageQuit("Could not open file");

    std::string outFileName = argv[1];
    outFileName.append(".replace");

    std::ofstream outFile(outFileName.c_str());
    if (outFile.good() == false)
        rageQuit("Could not open file");
    
    std::string buf;
    std::string loaded;
    do
    {
        std::getline(inFile, buf);
        loaded += buf;
        if (inFile.eof() == false)
            loaded += '\n';
    } while (inFile.eof() == false);
    
    loaded = findAndReplace(loaded, argv[2], argv[3]);
    outFile << loaded;

    return 0;
}
