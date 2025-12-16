#include "Cat.hpp"

Cat::Cat() {
    type = "Cat";
    std::cout << "Cat: kitten created" << std::endl;
}

Cat::~Cat() {
    std::cout << "Cat: destructor called (farewell feline)" << std::endl;
}

void Cat::makeSound() {
    std::cout << "Cat: Meow~" << std::endl;
}