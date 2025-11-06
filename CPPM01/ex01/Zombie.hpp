#include <string>
#include <iostream>
#include <sstream>

#pragma once
#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

class Zombie {
    private:
        std::string name;
    
    public:
        void announce();
        Zombie();
        ~Zombie();
        
        //Getter
        std::string getName() const;
        //Setter
        void setName(std::string& name);
    };
    Zombie* zombieHorde(int n, std::string name);
    Zombie* newZombie(std::string name);    


#endif