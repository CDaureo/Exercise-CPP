/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <cdaureo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 13:38:59 by cdaureo-          #+#    #+#             */
/*   Updated: 2026/09/08 14:10:50 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <cmath>
#include <cstdlib>

Base::~Base(){}

Base *generate(void)
{
    int random = rand() % 3;
    
    if (random == 0)
    {
        Base *a = new A();
        return a;
    }
    else if (random  == 1)
    {
         Base *b = new B();
        return b;
    } else if (random == 2)
    {
         Base *c = new C();
        return c;
    }
    return 0;
}
//Print object pointed "is this pointed really A?"
void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "NOTHING" << std::endl;
}
//Print object referenced
void identify(Base& p)
{
    try
    {
        A& a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "A" << std::endl;
        return;
    }
    catch(...)
    {
    }
        try
    {
        B& b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << "B" << std::endl;
        return;
    }
    catch(...)
    {
    }
        try
    {
        C& c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << "C" << std::endl;
        return;
    }
    catch(...)
    {
    }
}