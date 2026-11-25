/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <cdaureo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 12:11:07 by cdaureo-          #+#    #+#             */
/*   Updated: 2026/11/25 14:14:50 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <stdexcept>
#include <vector>

int main()
{
    Span example(5);
    example.addNumber(6);
    example.addNumber(3);
    example.addNumber(17);
    example.addNumber(9);
    example.addNumber(11);
    std::cout << example.shortestSpan() << std::endl; // 2
    std::cout << example.longestSpan() << std::endl;  // 14

    try
    {
        example.addNumber(42);
        std::cout << "Error al comprobar la capacidad" << std::endl;
        return 1;
    }
    catch (const std::length_error& error)
    {
        std::cout << error.what() << std::endl;
    }

    const int count = 2222222;
    std::vector<int> numbers;
    for (int i = 0; i < count; ++i)
        numbers.push_back(i);

    Span large(count);
    large.addNumber(numbers.begin(), numbers.end());
    const unsigned int shortest = large.shortestSpan();
    const unsigned int longest = large.longestSpan();

    std::cout << "Prueba con " << count << " numeros" << std::endl;
    std::cout << "Distancia minima = " << shortest << std::endl;
    std::cout << "Distancia maxima = " << longest << std::endl;
    return 0;
}
