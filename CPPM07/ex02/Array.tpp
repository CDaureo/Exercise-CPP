/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <cdaureo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 18:33:31 by cdaureo-          #+#    #+#             */
/*   Updated: 2026/09/21 19:03:25 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <cstddef>

template <typename T>
Array<T>::Array() : _data(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int num) : _data(new T[num]()), _size(num) {}

template <typename T>
Array<T>::~Array(){};

template <typename T>
Array<T>::Array(const Array& other) : _data(new T[other._size]()), _size(other._size)
{
    for (unsigned int i = 0; i < _size; i++)
    {
       _data[i] = other._data[i];
    }
}
//Devuelve in arefencia modificable que permite leer i escribir
template <typename T>
T& Array<T>::operator[](unsigned int index)
{
    if (index >= _size)
    {
        throw std::exception();
    }
    return _data[index];
}
// - const T&: no puedes modificar el elemento a través de la referencia devuelta.
// - El const final: el método no modifica los miembros del objeto y puede llamarse sobre un Array constante.
template <typename T>
const T& Array<T>::operator[](unsigned int index) const
{
        if (index >= _size)
    {
        throw std::exception();
    }
    return _data[index];
}
template <typename T>
unsigned int  Array<T>::size() const{ return _size; }
