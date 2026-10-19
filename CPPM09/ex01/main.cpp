#include "RPN.hpp"
#include <exception>
#include <iostream>

int main(int argc, char **argv)
{
    // Las comillas hacen que la expresión completa llegue como un argumento.
    if (argc != 2)
    {
        std::cerr << "Error: usage: ./RPN \"expression\"" << std::endl;
        return 1;
    }
    try
    {
        RPN calculator;
        std::cout << calculator.evaluate(argv[1]) << std::endl;
    }
    catch (const std::exception &error)
    {
        std::cerr << "Error: " << error.what() << std::endl;
        return 1;
    }
    return 0;
}
