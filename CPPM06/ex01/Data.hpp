/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <cdaureo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 10:42:41 by cdaureo-          #+#    #+#             */
/*   Updated: 2026/09/01 10:47:03 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP
#include <string>
//You must create a non-empty (meaning it has data members) Data structure

struct Data
{
    int id;
    std::string name;
    
    Data();
    Data(const Data & other);
    Data & operator = (const Data & other);
    ~Data();
};

#endif