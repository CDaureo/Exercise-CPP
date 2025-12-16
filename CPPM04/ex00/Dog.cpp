#include "Dog.hpp"

Dog::Dog() {
    type = "Dog";
    std::cout << "Dog: Doggy created" << std::endl;
}

Dog::~Dog() {
    std::cout << "Dog: destructor called (farewell feline)" << std::endl;
}

void Dog::makeSound() {
    std::cout << "Dog: Bark~" << std::endl;
}
