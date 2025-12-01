#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap()
: name("Unnamed"), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "ClapTrap default constructor called for " << name << std::endl;
}

ClapTrap::ClapTrap(const std::string& n)
: name(n), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "ClapTrap constructor called for " << name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
    *this = other;
    std::cout << "ClapTrap copy constructor called for " << name << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    if (this != &other) {
        name = other.name;
        hitPoints = other.hitPoints;
        energyPoints = other.energyPoints;
        attackDamage = other.attackDamage;
    }
    std::cout << "ClapTrap assignment operator called for " << name << std::endl;
    return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap destructor called for " << name << std::endl;
}

void ClapTrap::attack(const std::string& target) {
    if (energyPoints == 0 || hitPoints == 0) {
        std::cout << "ClapTrap " << name << " cannot attack (no energy or dead)." << std::endl;
        return;
    }
    --energyPoints;
    std::cout << "ClapTrap " << name << " attacks " << target
              << ", causing " << attackDamage << " points of damage! (EP left: " << energyPoints << ")" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (amount >= hitPoints) hitPoints = 0;
    else hitPoints -= amount;
    std::cout << "ClapTrap " << name << " takes " << amount << " damage. (HP: " << hitPoints << ")" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (energyPoints == 0) {
        std::cout << "ClapTrap " << name << " cannot repair (no energy)." << std::endl;
        return;
    }
    --energyPoints;
    hitPoints += amount;
    std::cout << "ClapTrap " << name << " repairs " << amount << " hit points. (HP: " << hitPoints << ", EP: " << energyPoints << ")" << std::endl;
}

const std::string& ClapTrap::getName() const { return name; }
unsigned int ClapTrap::getHitPoints() const { return hitPoints; }
unsigned int ClapTrap::getEnergyPoints() const { return energyPoints; }
unsigned int ClapTrap::getAttackDamage() const { return attackDamage; }