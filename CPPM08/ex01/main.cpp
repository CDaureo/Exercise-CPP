/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <cdaureo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 12:11:07 by cdaureo-          #+#    #+#             */
/*   Updated: 2026/10/07 12:11:08 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Span.hpp"
#include <climits>
#include <iostream>
#include <iterator>
#include <sstream>
#include <list>

static void check(bool condition, const char* message)
{
    if (!condition)
        throw std::runtime_error(message);
}

static void checkNoSpan(const Span& span)
{
    bool shortestThrew = false;
    bool longestThrew = false;
    try { span.shortestSpan(); }
    catch (const std::logic_error&) { shortestThrew = true; }
    try { span.longestSpan(); }
    catch (const std::logic_error&) { longestThrew = true; }
    check(shortestThrew && longestThrew, "Fallo: menos de dos numeros");
}

static void checkFull(Span& span)
{
    bool threw = false;
    try { span.addNumber(42); }
    catch (const std::length_error&) { threw = true; }
    check(threw, "Fallo: capacidad maxima");
}

int main()
{
    try
    {
        Span sp(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
        check(sp.shortestSpan() == 2 && sp.longestSpan() == 14,
            "Fallo: ejemplo del enunciado");
        checkFull(sp);

        Span defaultSpan;
        checkNoSpan(defaultSpan);
        checkFull(defaultSpan);
        Span zero(0);
        checkNoSpan(zero);
        checkFull(zero);
        Span single(2);
        checkNoSpan(single);
        single.addNumber(-5);
        checkNoSpan(single);
        single.addNumber(-5);
        check(single.shortestSpan() == 0 && single.longestSpan() == 0,
            "Fallo: duplicados");

        Span extremes(2);
        extremes.addNumber(INT_MAX);
        extremes.addNumber(INT_MIN);
        const unsigned int fullDistance = static_cast<unsigned int>(INT_MAX)
            - static_cast<unsigned int>(INT_MIN);
        check(extremes.shortestSpan() == fullDistance
            && extremes.longestSpan() == fullDistance, "Fallo: extremos int");

        int values[] = {-10, 8, -3, 0};
        Span range(5);
        range.addNumber(values, values + 4);
        check(range.shortestSpan() == 3 && range.longestSpan() == 18,
            "Fallo: rango con negativos");
        bool threw = false;
        try { range.addNumber(values, values + 2); }
        catch (const std::length_error&) { threw = true; }
        check(threw, "Fallo: rango demasiado grande");
        range.addNumber(20);
        check(range.shortestSpan() == 3 && range.longestSpan() == 30,
            "Fallo: rango rechazado modifica el Span");
        range.addNumber(values, values);
        checkFull(range);

        std::istringstream input("9 -4 2 15");
        Span streamed(4);
        streamed.addNumber(std::istream_iterator<int>(input),
            std::istream_iterator<int>());
        check(streamed.shortestSpan() == 6 && streamed.longestSpan() == 19,
            "Fallo: iteradores de entrada");

        Span original(3);
        original.addNumber(1);
        original.addNumber(5);
        Span copied(original);
        Span assigned(0);
        assigned = original;
        original.addNumber(3);
        copied.addNumber(10);
        assigned.addNumber(-5);
        assigned = assigned;
        check(original.longestSpan() == 4 && copied.longestSpan() == 9
            && assigned.longestSpan() == 10, "Fallo: copia independiente");
        checkFull(assigned);

        std::list<int> many;
        for (int i = 20000; i > 0; --i)
            many.push_back(i * 3);
        Span large(20000);
        large.addNumber(many.begin(), many.end());
        check(large.shortestSpan() == 3 && large.longestSpan() == 59997,
            "Fallo: 20000 numeros");
        checkFull(large);
        std::cout << "Todas las pruebas superadas (incluidos 20000 numeros)."
            << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
        return 1;
    }
    return 0;
}
