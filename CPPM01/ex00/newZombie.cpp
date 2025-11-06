#include "Zombie.hpp"

Zombie* newZombie(std::string name) //Esto es memoria dinamica
{
    Zombie* zombie = new Zombie();
    zombie->setName(name);
    return zombie;
}
