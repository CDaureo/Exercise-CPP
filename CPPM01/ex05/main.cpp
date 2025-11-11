#include <iostream>
#include "Harl.hpp"

int main(int argc, char const *argv[])
{
    Harl harl;
    if (argc != 2)
    {
        std::cout << "Solo puedes poner 1 argumento" << std::endl;
    }
    else
        harl.complain(std::string(argv[1]));
    return 0;
}
