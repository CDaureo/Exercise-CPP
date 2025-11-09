#include <string>
#include <iostream>
#include <sstream>

#pragma once
#ifndef __WEAPON_HPP__
#define __WEAPON_HPP__

class Weapon
{
private:
    std::string type;
public:
    Weapon(const std::string& type);
    ~Weapon();
    //Getter
    const std::string& getType();
    //Setter
    void setType(const std::string& type);
};




#endif