#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main() {
    std::cout << "=== Scope A: crear un FragTrap para ver la cadena de construcción ===" << std::endl;
    {
        FragTrap f("Frank");
        std::cout << "-- acciones de Frank --" << std::endl;
        f.attack("dummy_target");
        f.highFivesGuys();
    }
    std::cout << "=== Salimos del scope A: destructores deben mostrarse en orden inverso ===" << std::endl << std::endl;

    std::cout << "=== Scope B: mezcla ClapTrap, ScavTrap y FragTrap ===" << std::endl;
    {
        ClapTrap c("Clappy");
        ScavTrap s("Gatekeeper");
        FragTrap f2("Fiesta");
        f2.attack("intruder");
        s.attack("intruder");
        c.attack("intruder");
        f2.takeDamage(40);
        f2.beRepaired(25);
        s.guardGate();
        f2.highFivesGuys();
    }
    std::cout << "=== Fin ===" << std::endl;
    return 0;
}