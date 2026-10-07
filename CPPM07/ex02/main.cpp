/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <cdaureo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 18:27:20 by cdaureo-          #+#    #+#             */
/*   Updated: 2026/09/21 19:00:25 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>
int main(void)
{
  Array<int> numeros(3);

      numeros[0] = 42;

      std::cout << numeros[0] << std::endl;     // 42
      std::cout << numeros.size() << std::endl; // 3

      try
      {
          numeros[3] = 10; // Fuera de rango: solo existen 0, 1 y 2
      }
      catch (const std::exception& e)
      {
          std::cerr << "Indice fuera de rango: " << e.what() << std::endl;
      }

      return 0;
}
