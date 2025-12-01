#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap()
: ClapTrap("Unnamed_Scav") {
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "ScavTrap default constructor called for " << name << std::endl;
}

ScavTrap::ScavTrap(const std::string& n)
: ClapTrap(n) {
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "ScavTrap constructor called for " << name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other)
: ClapTrap(other) {
    std::cout << "ScavTrap copy constructor called for " << name << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    ClapTrap::operator=(other);
    std::cout << "ScavTrap assignment operator called for " << name << std::endl;
    return *this;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap destructor called for " << name << std::endl;
}

void ScavTrap::attack(const std::string& target) {
    if (energyPoints == 0 || hitPoints == 0) {
        std::cout << "ScavTrap " << name << " cannot attack (no energy or dead)." << std::endl;
        return;
    }
    --energyPoints;
    std::cout << "ScavTrap " << name << " fiercely attacks " << target
              << ", causing " << attackDamage << " points of damage! (EP left: " << energyPoints << ")" << std::endl;
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << name << " is now in Gate keeper mode." << std::endl;
}