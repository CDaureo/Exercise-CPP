#include "PmergeMe.hpp"
#include <ctime>
#include <iomanip>
#include <iostream>
#include <limits>
#include <stdexcept>

PmergeMe::Element::Element(int number, std::size_t identity)
    : value(number), id(identity) {}

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other)
    : _vector(other._vector), _deque(other._deque) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        _vector = other._vector;
        _deque = other._deque;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

int PmergeMe::parsePositive(const char *text)
{
    if (*text == '+')
        ++text;
    if (*text == '\0')
        throw std::invalid_argument("expected a positive integer");
    int value = 0;
    for (; *text; ++text)
    {
        if (*text < '0' || *text > '9')
            throw std::invalid_argument("expected a positive integer");
        const int digit = *text - '0';
        if (value > (std::numeric_limits<int>::max() - digit) / 10)
            throw std::out_of_range("integer exceeds INT_MAX");
        value = value * 10 + digit;
    }
    if (value == 0)
        throw std::invalid_argument("integers must be greater than zero");
    return value;
}

void PmergeMe::sortVector(std::vector<Element> &values)
{
    if (values.size() < 2)
        return;
    std::vector<Element> winners;
    std::vector<Element> losers;
    for (std::size_t i = 0; i + 1 < values.size(); i += 2)
    {
        // Cada pareja conserva su identidad aunque haya valores repetidos.
        if (values[i].value > values[i + 1].value)
        {
            winners.push_back(values[i]);
            losers.push_back(values[i + 1]);
        }
        else
        {
            winners.push_back(values[i + 1]);
            losers.push_back(values[i]);
        }
    }
    const std::vector<Element> originalWinners(winners);
    sortVector(winners);

    std::vector<Element> pending;
    for (std::size_t i = 0; i < winners.size(); ++i)
    {
        std::size_t pair = 0;
        while (originalWinners[pair].id != winners[i].id)
            ++pair;
        pending.push_back(losers[pair]);
    }
    if (values.size() % 2 != 0)
        pending.push_back(values.back());

    // b1 <= a1: se coloca directamente, sin otra comparación.
    std::vector<Element> chain(winners);
    chain.insert(chain.begin(), pending[0]);
    std::size_t inserted = 1;
    std::size_t previousJacob = 1;
    std::size_t jacob = 3;
    while (inserted < pending.size())
    {
        const std::size_t end = jacob < pending.size()
            ? jacob : pending.size();
        // Índices humanos: b3, b2, b5, b4, b11, b10, ..., b6.
        for (std::size_t index = end; index > inserted; --index)
        {
            const std::size_t current = index - 1;
            std::size_t right = chain.size();
            if (current < winners.size())
            {
                right = 0;
                while (chain[right].id != winners[current].id)
                    ++right;
            }
            // Buscar sólo ANTES de su pareja; el impar usa toda la cadena.
            std::size_t left = 0;
            while (left < right)
            {
                const std::size_t middle = left + (right - left) / 2;
                if (chain[middle].value < pending[current].value)
                    left = middle + 1;
                else
                    right = middle;
            }
            chain.insert(chain.begin() + left, pending[current]);
        }
        inserted = end;
        if (inserted == pending.size())
            break;
        // J(n) = J(n-1) + 2 * J(n-2), sin desbordar size_t.
        const std::size_t maximum = std::numeric_limits<std::size_t>::max();
        const std::size_t next = previousJacob > (maximum - jacob) / 2
            ? pending.size() : jacob + 2 * previousJacob;
        previousJacob = jacob;
        jacob = next;
    }
    values.swap(chain);
}

void PmergeMe::sortDeque(std::deque<Element> &values)
{
    if (values.size() < 2)
        return;
    std::deque<Element> winners;
    std::deque<Element> losers;
    for (std::size_t i = 0; i + 1 < values.size(); i += 2)
    {
        // Cada pareja conserva su identidad aunque haya valores repetidos.
        if (values[i].value > values[i + 1].value)
        {
            winners.push_back(values[i]);
            losers.push_back(values[i + 1]);
        }
        else
        {
            winners.push_back(values[i + 1]);
            losers.push_back(values[i]);
        }
    }
    const std::deque<Element> originalWinners(winners);
    sortDeque(winners);

    std::deque<Element> pending;
    for (std::size_t i = 0; i < winners.size(); ++i)
    {
        std::size_t pair = 0;
        while (originalWinners[pair].id != winners[i].id)
            ++pair;
        pending.push_back(losers[pair]);
    }
    if (values.size() % 2 != 0)
        pending.push_back(values.back());

    // b1 <= a1: se coloca directamente, sin otra comparación.
    std::deque<Element> chain(winners);
    chain.insert(chain.begin(), pending[0]);
    std::size_t inserted = 1;
    std::size_t previousJacob = 1;
    std::size_t jacob = 3;
    while (inserted < pending.size())
    {
        const std::size_t end = jacob < pending.size()
            ? jacob : pending.size();
        // Índices humanos: b3, b2, b5, b4, b11, b10, ..., b6.
        for (std::size_t index = end; index > inserted; --index)
        {
            const std::size_t current = index - 1;
            std::size_t right = chain.size();
            if (current < winners.size())
            {
                right = 0;
                while (chain[right].id != winners[current].id)
                    ++right;
            }
            // Buscar sólo ANTES de su pareja; el impar usa toda la cadena.
            std::size_t left = 0;
            while (left < right)
            {
                const std::size_t middle = left + (right - left) / 2;
                if (chain[middle].value < pending[current].value)
                    left = middle + 1;
                else
                    right = middle;
            }
            chain.insert(chain.begin() + left, pending[current]);
        }
        inserted = end;
        if (inserted == pending.size())
            break;
        // J(n) = J(n-1) + 2 * J(n-2), sin desbordar size_t.
        const std::size_t maximum = std::numeric_limits<std::size_t>::max();
        const std::size_t next = previousJacob > (maximum - jacob) / 2
            ? pending.size() : jacob + 2 * previousJacob;
        previousJacob = jacob;
        jacob = next;
    }
    values.swap(chain);
}

void PmergeMe::run(int argc, char **argv)
{
    if (argc < 2)
        throw std::invalid_argument("usage: ./PmergeMe positive_integer [...]");

    // Cada medición incluye validación, carga y auxiliares del algoritmo.
    const std::clock_t vectorStart = std::clock();
    _vector.clear();
    _vector.reserve(argc - 1);
    for (int i = 1; i < argc; ++i)
        _vector.push_back(Element(parsePositive(argv[i]), i - 1));
    sortVector(_vector);
    const std::clock_t vectorEnd = std::clock();

    const std::clock_t dequeStart = std::clock();
    _deque.clear();
    for (int i = 1; i < argc; ++i)
        _deque.push_back(Element(parsePositive(argv[i]), i - 1));
    sortDeque(_deque);
    const std::clock_t dequeEnd = std::clock();
    if (vectorStart == std::clock_t(-1) || vectorEnd == std::clock_t(-1)
        || dequeStart == std::clock_t(-1) || dequeEnd == std::clock_t(-1))
        throw std::runtime_error("could not measure CPU time");

    for (std::size_t i = 0; i < _vector.size(); ++i)
        if (_vector[i].value != _deque[i].value)
            throw std::logic_error("container results differ");

    std::cout << "Before:";
    for (int i = 1; i < argc; ++i)
        std::cout << ' ' << argv[i];
    std::cout << "\nAfter:";
    for (std::size_t i = 0; i < _vector.size(); ++i)
        std::cout << ' ' << _vector[i].value;
    const double vectorTime = (static_cast<double>(vectorEnd)
        - static_cast<double>(vectorStart)) * 1000000.0 / CLOCKS_PER_SEC;
    const double dequeTime = (static_cast<double>(dequeEnd)
        - static_cast<double>(dequeStart)) * 1000000.0 / CLOCKS_PER_SEC;
    std::cout << std::fixed << std::setprecision(3)
        << "\nTime to process a range of " << _vector.size()
        << " elements with std::vector : " << vectorTime << " us"
        << "\nTime to process a range of " << _deque.size()
        << " elements with std::deque : " << dequeTime << " us" << std::endl;
}
