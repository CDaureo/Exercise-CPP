/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <cdaureo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 10:38:19 by cdaureo-          #+#    #+#             */
/*   Updated: 2026/09/01 10:53:06 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"


Serialization::Serialization()
{}

Serialization::Serialization(const Serialization &other)
{
    (void)other;
}

Serialization &Serialization::operator=(const Serialization &other)
{ 
    (void)other;
    return *this;
}

Serialization::~Serialization()
{}

uintptr_t Serialization::serialize(Data* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}
Data* Serialization::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data*>(raw);
}
