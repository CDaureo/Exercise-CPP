#ifndef CAT_H
#define CAT_H

#include "Animal.hpp"

class Cat : public Animal {
    public:
        Cat();
        ~Cat();
        void makeSound();
};

#endif