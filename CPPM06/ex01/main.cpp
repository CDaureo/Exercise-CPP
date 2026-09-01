/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <cdaureo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 10:53:13 by cdaureo-          #+#    #+#             */
/*   Updated: 2026/09/01 11:04:00 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"
#include <iostream>

int main()
{
    Data original;
    uintptr_t raw;
    Data *restored;

    original.id = 42;
    original.name = "test";
    raw = Serialization::serialize(&original);
    restored = Serialization::deserialize(raw);
    std::cout << "Original ptr:   " << &original << std::endl;
    std::cout << "Serialized raw: " << raw << std::endl;
    std::cout << "Restored ptr:   " << restored << std::endl;
    std::cout << "Same pointer:   " << (&original == restored) << std::endl;
    std::cout << "Data:           " << restored->id << ", " << restored->name << std::endl;
    return (0);
}
