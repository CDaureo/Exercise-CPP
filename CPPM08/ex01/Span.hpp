#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>

class Span
{
private:
    unsigned int _capacity;
    std::vector<int> _numbers;

public:
    Span();
    explicit Span(unsigned int n);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();

    void addNumber(int number);
    unsigned int shortestSpan() const;
    unsigned int longestSpan() const;

    template <typename InputIterator>
    void addNumber(InputIterator first, InputIterator last)
    {
        // Preparamos el rango antes de modificar el Span: si no cabe,
        // se lanza una excepcion y los numeros originales se conservan.
        std::vector<int> pending;
        const std::vector<int>::size_type available =
            _capacity - _numbers.size();
        for (; first != last; ++first)
        {
            if (pending.size() == available)
                throw std::length_error("Span: capacidad insuficiente");
            pending.push_back(*first);
        }
        _numbers.insert(_numbers.end(), pending.begin(), pending.end());
    }
};

#endif
