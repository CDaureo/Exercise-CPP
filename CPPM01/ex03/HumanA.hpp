#include <string>
#include <iostream>
#include "Weapon.hpp"

#pragma once
#ifndef __HUMANA_HPP__
#define __HUMANA_HPP__

class HumanA
{
    private:
        std::string name;
        Weapon& weapon;
    public:
        void attack();
        HumanA(const std::string&name, Weapon& weapon);
};

#endif