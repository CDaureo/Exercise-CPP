/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <cdaureo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 12:11:22 by cdaureo-          #+#    #+#             */
/*   Updated: 2026/10/13 11:51:59 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>

Span::Span() : _capacity(0) {}

Span::Span(unsigned int n) : _capacity(n) {}

Span::Span(const Span& other)
    : _capacity(other._capacity), _numbers(other._numbers) {}

Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {
        _numbers = other._numbers;
        _capacity = other._capacity;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int number)
{
    if (_numbers.size() == _capacity)
        throw std::length_error("Span: capacidad insuficiente");
    _numbers.push_back(number);
}

unsigned int Span::shortestSpan() const
{
    if (_numbers.size() < 2)
        throw std::logic_error("Span: hacen falta al menos dos numeros");
    std::vector<int> sorted(_numbers);
    std::sort(sorted.begin(), sorted.end());
    unsigned int shortest = static_cast<unsigned int>(sorted[1])
        - static_cast<unsigned int>(sorted[0]);
    for (std::vector<int>::size_type i = 2; i < sorted.size(); ++i)
    {
        // La resta sin signo evita overflow incluso entre INT_MIN e INT_MAX.
        const unsigned int distance = static_cast<unsigned int>(sorted[i])
            - static_cast<unsigned int>(sorted[i - 1]);
        if (distance < shortest)
            shortest = distance;
    }
    return shortest;
}

unsigned int Span::longestSpan() const
{
    if (_numbers.size() < 2)
        throw std::logic_error("Span: hacen falta al menos dos numeros");
    const int minimum = *std::min_element(_numbers.begin(), _numbers.end());
    const int maximum = *std::max_element(_numbers.begin(), _numbers.end());
    return static_cast<unsigned int>(maximum)
        - static_cast<unsigned int>(minimum);
}
