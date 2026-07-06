#include <iostream>


int main ()
{
    int edad;
    try {
        std::cout << "Starting the application..." << std::endl;
        std::cin >> edad;
    }
    catch (const std::exception& msg) {
        std::cerr << "An error occurred: " << msg.what() << std::endl;
    }
}