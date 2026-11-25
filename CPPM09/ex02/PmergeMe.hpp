#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <cstddef>
#include <deque>
#include <vector>

class PmergeMe
{
private:
    struct Element
    {
        int value;
        std::size_t id;
        Element(int number = 0, std::size_t identity = 0);
    };

    std::vector<Element> _vector;
    std::deque<Element> _deque;
    static int parsePositive(const char *text);
    static std::size_t findInsertPosition(const std::vector<Element> &chain,
        std::size_t right, int value);
    static std::size_t findInsertPosition(const std::deque<Element> &chain,
        std::size_t right, int value);
    static void sortVector(std::vector<Element> &values);
    static void sortDeque(std::deque<Element> &values);

public:
    PmergeMe();
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);
    ~PmergeMe();

    void run(int argc, char **argv);
};

#endif
