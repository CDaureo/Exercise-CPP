#include "Animal.hpp"

Animal::Animal() : type("Animal") {
    std::cout << "Animal: base constructor called" << std::endl;
}

Animal::~Animal() {
    std::cout << "Animal: base destructor called" << std::endl;
}

void Animal::makeSound() {
    std::cout << "Animal: generic silence..." << std::endl;
}

std::string Animal::getType() {
    return type;
}