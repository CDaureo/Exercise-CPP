/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <cdaureo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 12:54:37 by cdaureo-          #+#    #+#             */
/*   Updated: 2026/09/16 13:03:33 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP
#include <cstddef>

template <typename A, typename F>
void iter(A* array, const std::size_t len, F f)
{
    for (std::size_t i = 0; i < len; i++)
    {
        f(array[i]);
        
    }
}

#endif