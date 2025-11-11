#include <iostream>
#include "Harl.hpp"

int main(int argc, char const *argv[])
{
    Harl harl;
    if (argc != 2)
    {
        std::cout << "Uso: " << argv[0] << " <LEVEL>\n";
        std::cout << "Niveles válidos: DEBUG, INFO, WARNING, ERROR\n";
        return 1;
    }
    harl.complain(std::string(argv[1]));
    return 0;
}
