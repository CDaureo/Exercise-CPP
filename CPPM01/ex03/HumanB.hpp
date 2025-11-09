#pragma once
#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <string>
#include "Weapon.hpp"

class HumanB
{
public:
    HumanB(const std::string& name);
    void setWeapon(Weapon& weapon);
    void attack();

private:
    std::string name;
    Weapon* weapon; // puntero: puede ser nullptr (no siempre armado)
};

#endif