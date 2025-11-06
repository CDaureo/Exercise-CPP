#include "Zombie.hpp"

Zombie* zombieHorde(int n, std::string name)
{
    if (n <= 0)
    {
        return NULL;
    }
    
    Zombie* horda = new Zombie[n];
    for(int i = 0; i < n; i++)
        horda[i].setName(name);

    return horda;
}