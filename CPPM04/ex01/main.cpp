#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <vector>

int main() {
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;
    delete i;

    // Array mitad Dog mitad Cat
    const int N = 6;
    Animal* zoo[N];
    for (int k = 0; k < N; ++k) {
        if (k < N / 2)
            zoo[k] = new Dog();
        else
            zoo[k] = new Cat();
    }
    for (int k = 0; k < N; ++k) {
        zoo[k]->makeSound();
    }
    for (int k = 0; k < N; ++k) {
        delete zoo[k]; // polimórfico
    }

    // Prueba de copia profunda
    Dog d1;
    d1.setIdea(0, "chase cats");
    Dog d2 = d1;              // copy ctor
    d2.setIdea(0, "eat treats");
    std::cout << "d1 idea: " << d1.getIdea(0) << std::endl;
    std::cout << "d2 idea: " << d2.getIdea(0) << std::endl;

    Cat c1;
    c1.setIdea(1, "sleep");
    Cat c2;
    c2 = c1;                  // copy assign
    c2.setIdea(1, "climb");
    std::cout << "c1 idea: " << c1.getIdea(1) << std::endl;
    std::cout << "c2 idea: " << c2.getIdea(1) << std::endl;

    return 0;
}