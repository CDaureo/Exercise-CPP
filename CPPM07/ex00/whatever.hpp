/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <cdaureo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 12:37:03 by cdaureo-          #+#    #+#             */
/*   Updated: 2026/11/23 16:18:19 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>
void swap(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}
template <typename M>
const M& max(const M& a, const M& b)
{
if (a > b)
    return a;
else
    return b;
}
template <typename N>

const N& min(const N& a, const N& b)
{
if (a < b)
    return a;
else
    return b;
}
#endif