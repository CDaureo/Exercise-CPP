#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main() {
    std::cout << "=== Scope 1: crear un ScavTrap para ver la cadena de construcción ===" << std::endl;
    {
        ScavTrap s("Serena");
        std::cout << "-- acciones de Serena --" << std::endl;
        s.attack("dummy");
        s.guardGate();
    }
    std::cout << "=== Salimos del scope 1: destructores deben mostrarse en orden inverso ===" << std::endl << std::endl;

    std::cout << "=== Scope 2: mezcla ClapTrap y ScavTrap ===" << std::endl;
    {
        ClapTrap c("Clappy");
        ScavTrap s2("Gatekeeper");
        s2.attack("intruder");
        c.attack("intruder");
        s2.takeDamage(30);
        s2.beRepaired(20);
    }
    std::cout << "=== Fin ===" << std::endl;
    return 0;
}