#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap()
: ClapTrap("Unnamed_Frag") {
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap: default constructor called for " << name << std::endl;
}

FragTrap::FragTrap(const std::string& n)
: ClapTrap(n) {
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap: constructor called for " << name << std::endl;
}

FragTrap::FragTrap(const FragTrap& other)
: ClapTrap(other) {
    std::cout << "FragTrap: copy constructor called for " << name << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    std::cout << "FragTrap: assignment operator called for " << name << std::endl;
    return *this;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap: destructor called for " << name << std::endl;
}

void FragTrap::attack(const std::string& target) {
    if (energyPoints == 0 || hitPoints == 0) {
        std::cout << "FragTrap " << name << " cannot attack (no energy or dead)." << std::endl;
        return;
    }
    --energyPoints;
    std::cout << "FragTrap " << name << " launches a heavy strike on " << target
              << ", dealing " << attackDamage << " points of damage! (EP left: " << energyPoints << ")" << std::endl;
}

void FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap " << name << " requests a positive high five! ✋" << std::endl;
}