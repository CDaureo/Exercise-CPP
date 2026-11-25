/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <cdaureo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 11:46:42 by cdaureo-          #+#    #+#             */
/*   Updated: 2026/11/25 14:03:51 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <list>
#include <cstddef>
#include <vector>

static void checkMissing(const std::vector<int>& values, int number)
{
    try
    {
        easyfind(values, number);
    }
    catch (const std::runtime_error&)
    {
        return;
    }
    throw std::runtime_error("Fallo: se encontro un numero ausente");
}

int main()
{
    int values[] = {4,7,3,4,6,88};
    std::size_t size = sizeof(values) / sizeof(values[0]);
    std::list<int> list(values, values + size);
    try
    {
        std::list<int>::iterator it = easyfind(list, 4);

        const std::vector<int> vector(values, values + size);
        if (easyfind(vector, 4) != vector.begin())
            throw std::runtime_error("Fallo: debe devolver la primera coincidencia");
        checkMissing(vector, 42);
        checkMissing(std::vector<int>(), 4);

        std::cout << "Numero encontrado: " << *it << " en la posicion: " << std::distance(list.begin(), it) << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
        return 1;
    }
    return 0;
}
