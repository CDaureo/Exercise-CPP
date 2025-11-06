#include "Zombie.hpp"

int main(int argc, char const *argv[])
{
    if (argc != 3)
    {
        std::cerr << "No se ha creado" << std::endl;
        return 1;
    }
    std::stringstream ss(argv[1]);
    int n;
    if (!(ss >> n) || n <= 0)
    {
        std::cerr << "error no es numero positivo" << std::endl;
        return 1;
    }
    std::string name = argv[2];

    Zombie* horda = zombieHorde(n, name);
    if (!horda)
    {
        std::cerr << "error al crear la horda de zombies" << std::endl;
        return 1;
    }
    for (int i = 0; i < n; i++)
        horda[i].announce();

    delete[] horda;
    return 0;
}
