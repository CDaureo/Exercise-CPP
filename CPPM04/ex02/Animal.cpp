#include "Animal.hpp"

Animal::Animal() : type("Animal") {
    std::cout << "Animal: ctor\n";
}

Animal::Animal(const Animal& other) : type(other.type) {
    std::cout << "Animal: copy ctor\n";
}

Animal& Animal::operator=(const Animal& other) {
    if (this != &other) type = other.type;
    std::cout << "Animal: copy assign\n";
    return *this;
}

Animal::~Animal() {
    std::cout << "Animal: dtor\n";
}

std::string Animal::getType() const {
    return type;
}