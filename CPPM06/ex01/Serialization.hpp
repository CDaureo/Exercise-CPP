/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <cdaureo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 10:38:28 by cdaureo-          #+#    #+#             */
/*   Updated: 2026/09/01 10:52:35 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZATION_HPP
#define SERIALIZATION_HPP
#include <stdint.h>
#include "Data.hpp"

class Serialization
{
    public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
    private:
        Serialization();
        Serialization(const Serialization &other);
        Serialization &operator=(const Serialization &other);
        ~Serialization();
};

#endif