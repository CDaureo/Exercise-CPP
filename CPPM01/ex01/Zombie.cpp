#include "Zombie.hpp"

Zombie::Zombie() : name("")
{

}
Zombie::~Zombie()
{
    std::cout << "El zombie " + name + " se destruyó" << std::endl;
}

std::string Zombie::getName() const
{
    return name;
}
void Zombie::setName(std::string& name)
{
    this->name = name;
}
void Zombie::announce()
{
    std::cout << name + ":" + " BraiiiiiiinnnzzzZ..." << std::endl;
}


