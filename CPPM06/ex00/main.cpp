/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <cdaureo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 11:32:26 by cdaureo-          #+#    #+#             */
/*   Updated: 2026/08/17 14:23:21 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

#include <iostream>

// Prints the expected program usage when the argument count is invalid.
void printUsage() {
    std::cout << "Usage: ./convert <literal>" << std::endl;
    std::cout << "Example: ./convert 42" << std::endl;
    std::cout << "         ./convert 3.14" << std::endl;
    std::cout << "         ./convert 'a'" << std::endl;
}

int main(int argc, char* argv[])
{
    if (argc != 2) {
        printUsage();
        return 1;
    }
    ScalarConverter::convert(argv[1]);
    
    return 0;
}
