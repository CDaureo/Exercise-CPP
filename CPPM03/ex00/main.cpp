#include "ClapTrap.hpp"

int main()
{
    ClapTrap a("CT-Alpha");
    a.attack("target-1");
    a.takeDamage(3);
    a.beRepaired(5);

    // Agotar energía
    for (int i = 0; i < 12; ++i)
        a.attack("dummy");

    // Dañar hasta 0 HP
    a.takeDamage(20);
    a.beRepaired(2); // no podrá repararse porque HP==0

    return 0;
}