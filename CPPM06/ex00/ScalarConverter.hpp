/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <cdaureo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 11:27:45 by cdaureo-          #+#    #+#             */
/*   Updated: 2026/08/17 12:30:13 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>

class ScalarConverter 
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter& operator=(const ScalarConverter& other);
        ~ScalarConverter();
        
        static bool parseChar(const std::string& literal, char& res);
        static bool parseInt(const std::string& literal, int& res);
        static bool parseFloat(const std::string& literal, float& res);
        static bool parseDouble(const std::string& literal, double& res);
        static void printFromChar(char value);
        static void printFromInt(int value);
        static void printFromFloat(float value);
        static void printFromDouble(double value);
    public:
        static void convert(const std::string& literal);
};

#endif
