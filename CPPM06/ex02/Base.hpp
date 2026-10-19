/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <cdaureo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 13:38:57 by cdaureo-          #+#    #+#             */
/*   Updated: 2026/09/08 14:01:55 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP
#include <iostream>

class Base
{
    public:
        virtual ~Base();

};
Base *generate(void);
void identify(Base* p);
void identify(Base& p);
class A : public Base{
};
class B : public Base {
};
class C : public Base {
};
#endif