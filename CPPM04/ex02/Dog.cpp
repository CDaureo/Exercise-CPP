#include "Dog.hpp"

Dog::Dog() : brain(new Brain()) {
    type = "Dog";
    std::cout << "Dog: ctor\n";
}

Dog::Dog(const Dog& other) : Animal(other), brain(new Brain(*other.brain)) {
    std::cout << "Dog: copy ctor\n";
}

Dog& Dog::operator=(const Dog& other) {
    if (this != &other) {
        Animal::operator=(other);
        *brain = *other.brain; // deep copy
    }
    std::cout << "Dog: copy assign\n";
    return *this;
}

Dog::~Dog() {
    delete brain;
    std::cout << "Dog: dtor\n";
}

void Dog::makeSound() const {
    std::cout << "Dog: Woof!\n";
}

void Dog::setIdea(size_t idx, const std::string& idea) { brain->setIdea(idx, idea); }
std::string Dog::getIdea(size_t idx) const { return brain->getIdea(idx); }
