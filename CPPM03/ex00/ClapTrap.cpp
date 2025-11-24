#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
: _name("ClapTrap"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap " << _name << " constructor" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name)
: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap " << _name << " constructor" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
: _name(other._name), _hitPoints(other._hitPoints), _energyPoints(other._energyPoints), _attackDamage(other._attackDamage)
{
    std::cout << "ClapTrap " << _name << " copia-constructor" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    if (this != &other) {
        _name = other._name;
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
    }
    std::cout << "ClapTrap " << _name << " asignado" << std::endl;
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << _name << " destruido" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (_hitPoints == 0) {
        std::cout << "ClapTrap " << _name << " no tiene hit points y no puede atacar." << std::endl;
        return;
    }
    if (_energyPoints == 0) {
        std::cout << "ClapTrap " << _name << " no tiene energia y no puede atacar." << std::endl;
        return;
    }
    --_energyPoints;
    std::cout << "ClapTrap " << _name << " ataca " << target << ", haciendo " << _attackDamage << " puntos de daño!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (_hitPoints == 0) {
        std::cout << "ClapTrap " << _name << " ya tiene 0 puntos de vida." << std::endl;
        return;
    }
    if (amount >= _hitPoints)
        _hitPoints = 0;
    else
        _hitPoints -= amount;
    std::cout << "ClapTrap " << _name << " recibe " << amount << " puntos de daño,  PS Restantes: " << _hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (_hitPoints == 0) {
        std::cout << "ClapTrap " << _name << " no tiene HP y no puede ser reparado." << std::endl;
        return;
    }
    if (_energyPoints == 0) {
        std::cout << "ClapTrap " << _name << " no tiene energia y no puede reparar." << std::endl;
        return;
    }
    --_energyPoints;
    _hitPoints += amount;
    std::cout << "ClapTrap " << _name << " es reparado por " << amount << " puntos, PS Actuales: " << _hitPoints << std::endl;
}