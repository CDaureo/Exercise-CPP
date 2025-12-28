#ifndef BRAIN_H
#define BRAIN_H

#include <string>
#include <iostream>

class Brain {
private:
    std::string ideas[100];
public:
    Brain();
    Brain(const Brain& other);
    Brain& operator=(const Brain& other);
    ~Brain();

    void setIdea(size_t idx, const std::string& idea);
    std::string getIdea(size_t idx) const;
};

#endif

