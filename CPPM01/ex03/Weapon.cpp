#include "Weapon.hpp"

Weapon::Weapon(const std::string& type) : type(type) {}

const std::string& Weapon::getType()
{
    return type;
}
void Weapon::setType(const std::string& t)
{
    type = t;
}

Weapon::~Weapon()
{
    std::cout << "Arma eliminada" << std::endl; 
}
