#include "Replacer.hpp"
#include <iostream>

int main(int argc, char const *argv[])
{
    if (argc != 4)
    {
        std::cerr << "Uso: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
        return 1;
    }

    std::string filename(argv[1]);
    std::string s1(argv[2]);
    std::string s2(argv[3]);

    try
    {
        Replacer replacer(filename, s1, s2);
        replacer.process();
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
