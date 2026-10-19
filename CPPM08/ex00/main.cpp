/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <cdaureo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 11:46:42 by cdaureo-          #+#    #+#             */
/*   Updated: 2026/10/07 12:09:03 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <list>
#include <cstddef>

//sizeof(values) devuelve el tamaño en bytes. Al dividirlo 
//   entre el tamaño de un elemento, obtienes cuántos elementos hay.
int main()
{
    int values[] = {4,7,3,4,6,89};
    std::size_t size = sizeof(values) / sizeof(values[0]);
    std::list<int> list(values, values + size);  
    try
    {
        std::list<int>::iterator it = easyfind(list, 89);
        std::cout << "Numero encontrado: " << *it << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
        return 1;
    }
    return 0;
}
