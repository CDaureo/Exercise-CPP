/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <cdaureo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 13:49:33 by cdaureo-          #+#    #+#             */
/*   Updated: 2026/09/08 14:09:42 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
    std::srand(std::time(NULL));
    Base* ptr = generate();
    //Pointer
    identify(ptr);
    //reference
    identify(*ptr);
    delete ptr;
    return 0;
}
