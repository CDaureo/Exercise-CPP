#include "PmergeMe.hpp"
#include <exception>
#include <iostream>

// Ejecuta el ordenador con los argumentos recibidos. Si hay una excepción,
// muestra el error y devuelve 1; si termina correctamente, devuelve 0.
int main(int argc, char **argv)
{
    try
    {
        PmergeMe sorter;
        sorter.run(argc, argv);
    }
    catch (const std::exception &error)
    {
        std::cerr << "Error: " << error.what() << std::endl;
        return 1;
    }
    return 0;
}
