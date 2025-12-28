#include "Brain.hpp"

Brain::Brain() {
    std::cout << "Brain: ctor\n";
}

Brain::Brain(const Brain& other) {
    for (size_t i = 0; i < 100; ++i) ideas[i] = other.ideas[i];
    std::cout << "Brain: copy ctor\n";
}

Brain& Brain::operator=(const Brain& other) {
    if (this != &other) {
        for (size_t i = 0; i < 100; ++i) ideas[i] = other.ideas[i];
    }
    std::cout << "Brain: copy assign\n";
    return *this;
}

Brain::~Brain() {
    std::cout << "Brain: dtor\n";
}

void Brain::setIdea(size_t idx, const std::string& idea) {
    if (idx < 100) ideas[idx] = idea;
}

std::string Brain::getIdea(size_t idx) const {
    return idx < 100 ? ideas[idx] : "";
}

