#include "Zombie.hpp"

int main(int argc, char const *argv[])
{
    if (argc == 2)
    {
        std::string name = argv[1];
        randomChump(name);
    }
    
    return 0;
}
