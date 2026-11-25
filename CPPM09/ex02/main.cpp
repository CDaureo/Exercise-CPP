#include "PmergeMe.hpp"
#include <exception>
#include <iostream>

// Sorts the values passed as arguments. If an exception occurs,
// prints the error and returns 1. Returns 0 on success.
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
