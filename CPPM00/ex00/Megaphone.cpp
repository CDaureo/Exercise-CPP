/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <cdaureo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 13:27:23 by cdaureo-          #+#    #+#             */
/*   Updated: 2026/01/08 12:01:33 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream> // Permite el uso de std::cout, std::endl
#include <string>
#include <cctype>
int main(int argc, char **argv) {
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}

	for (int i = 1; i < argc; i++)
	{
		char c = '\0';
		for (size_t j = 0; argv[i][j]; j++)
		{
			c = std::toupper(argv[i][j]);
			std::cout << c;
		}
	}
	std::cout << std::endl;
	return 0;
}