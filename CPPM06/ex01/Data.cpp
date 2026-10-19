/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <cdaureo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 10:45:17 by cdaureo-          #+#    #+#             */
/*   Updated: 2026/09/01 10:50:10 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data(): id(1), name("No Name")
{}

Data::Data(const Data &other) : id(other.id), name(other.name)
{}

Data &Data::operator=(const Data &other)
{
    if (this != &other)
    {
        id = other.id;
        name = other.name;
    }
    return *this;   
}

Data::~Data()
{}