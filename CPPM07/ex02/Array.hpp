/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <cdaureo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 18:27:22 by cdaureo-          #+#    #+#             */
/*   Updated: 2026/09/21 19:01:52 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP
# include <exception>
template <typename T>
class Array
{
    private:
        T* _data;
        unsigned int _size;
    public:
        Array();
        Array(unsigned int num);
        Array(const Array& other);
        Array& operator=(const Array& other);
        ~Array();
        T& operator[](unsigned int index);
        const T& operator[](unsigned int index) const;
        unsigned int size() const;
};
#include "Array.tpp"
#endif