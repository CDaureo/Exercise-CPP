/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <cdaureo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 13:03:48 by cdaureo-          #+#    #+#             */
/*   Updated: 2026/09/16 13:06:04 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <cassert>
#include <iostream>
#include <string>

// Function template that takes a const reference.
template <typename T>
void printElement(const T& element)
{
    std::cout << element << " ";
}

// Function template that modifies the original element.
template <typename T>
void increment(T& element)
{
    ++element;
}

void addExclamation(std::string& element)
{
    element += "!";
}

struct Point
{
    int x;
    int y;
};

void movePoint(Point& point)
{
    point.x += 1;
    point.y += 2;
}

void printPoint(const Point& point)
{
    std::cout << "(" << point.x << ", " << point.y << ") ";
}

int main()
{
    // Mutable array with functions taking const T& and T&.
    int numbers[] = {1, 2, 3};
    std::cout << "Enteros antes: ";
    ::iter(numbers, 3, printElement<int>);
    ::iter(numbers, 3, increment<int>);
    assert(numbers[0] == 2 && numbers[1] == 3 && numbers[2] == 4);
    std::cout << "\nEnteros despues: ";
    ::iter(numbers, 3, printElement<int>);

    double decimals[] = {0.5, 1.5, 2.5};
    ::iter(decimals, 3, increment<double>);
    assert(decimals[0] == 1.5 && decimals[1] == 2.5 && decimals[2] == 3.5);
    std::cout << "\nDecimales despues: ";
    ::iter(decimals, 3, printElement<double>);

    std::string words[] = {"Hola", "Mundo"};
    ::iter(words, 2, addExclamation);
    assert(words[0] == "Hola!" && words[1] == "Mundo!");
    std::cout << "\nCadenas despues: ";
    ::iter(words, 2, printElement<std::string>);

    // Const arrays: iter deduces A as const int / const std::string.
    const int constants[] = {10, 20, 30};
    std::cout << "\nEnteros constantes: ";
    ::iter(constants, 3, printElement<int>);
    const std::string labels[] = {"uno", "dos"};
    std::cout << "\nCadenas constantes: ";
    ::iter(labels, 2, printElement<std::string>);

    // Also works with user-defined types.
    Point points[] = {{1, 2}, {3, 4}};
    ::iter(points, 2, movePoint);
    assert(points[0].x == 2 && points[0].y == 4);
    assert(points[1].x == 4 && points[1].y == 6);
    std::cout << "\nPuntos despues: ";
    ::iter(points, 2, printPoint);

    // Zero length: must not call the function or modify the array.
    int untouched[] = {42};
    ::iter(untouched, 0, increment<int>);
    assert(untouched[0] == 42);

    // Only iterate over the specified number of elements.
    int partial[] = {5, 6, 7};
    ::iter(partial, 2, increment<int>);
    assert(partial[0] == 6 && partial[1] == 7 && partial[2] == 7);

    // ::iter(constants, 3, increment<int>);

    std::cout << "\nTodas las pruebas han pasado." << std::endl;
    return 0;
}
