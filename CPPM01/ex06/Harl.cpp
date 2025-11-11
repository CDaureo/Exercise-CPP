#include "Harl.hpp"
#include <iostream>

Harl::Harl() {}
Harl::~Harl() {}

void Harl::debug(void)
{
    std::cout << "DEBUG: ¡Me encanta que me den Poké Balls extra para mi equipo de 6 Pokémon legendarios! ¡De verdad!\n";
}

void Harl::info(void)
{
    std::cout << "INFO: No puedo creer que no pueda capturar más Pokémon. ¡No compré suficientes Poké Balls! Si lo hubieras hecho, no estaría pasando esto.\n";
}

void Harl::warning(void)
{
    std::cout << "WARNING: Creo que merezco una poción extra gratis. Llevo viniendo a este Gimnasio durante años, mientras que tú empezaste aquí hace poco.\n";
}

void Harl::error(void)
{
    std::cout << "ERROR: ¡Esto es inaceptable! Quiero hablar con el Líder de Gimnasio ahora mismo.\n";
}

void Harl::complain(std::string level)
{
    const std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harl::*privateFunctions[])() = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };

    int idx = -1;
    for (size_t i = 0; i < 4; ++i)
    {
        if (levels[i] == level)
        {
            idx = static_cast<int>(i);
            break;
        }
    }

    // usar switch obligatorio; aprovechar el fallthrough para imprimir desde el nivel dado hacia arriba
    switch (idx)
    {
        case 0:
            (this->*privateFunctions[0])();
            // fallthrough
        case 1:
            (this->*privateFunctions[1])();
            // fallthrough
        case 2:
            (this->*privateFunctions[2])();
            // fallthrough
        case 3:
            (this->*privateFunctions[3])();
            break;
        default:
            std::cout << "Harl no entiende el nivel: " << level << "\n";
            break;
    }
}