/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <cdaureo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 11:32:26 by cdaureo-          #+#    #+#             */
/*   Updated: 2026/08/17 14:23:21 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

#include <iostream>
#include <string>
#include <cstdlib>
#include <cerrno>
#include <climits>
#include <cfloat>
#include <cmath>

// Prints the expected program usage when the argument count is invalid.
void printUsage() {
    std::cout << "Usage: ./scalar_converter <literal>" << std::endl;
    std::cout << "Example: ./scalar_converter 42" << std::endl;
    std::cout << "         ./scalar_converter 3.14" << std::endl;
    std::cout << "         ./scalar_converter 'a'" << std::endl;
}

// Accepts a single non-digit character as a char literal.
bool ScalarConverter::parseChar(const std::string& literal, char& res)
{
    if (literal.length() != 1 || std::isdigit(static_cast<unsigned char>(literal[0])))
        return false;
    res = literal[0];
    return true;
}

// Parses a base-10 integer and rejects overflow or trailing characters.
bool ScalarConverter::parseInt(const std::string& literal, int& res) 
{
    char* end;
    errno = 0;
    long val = std::strtol(literal.c_str(), &end, 10);
    if (*end != '\0' || errno == ERANGE || val > INT_MAX || val < INT_MIN) 
        return false;
    res = static_cast<int>(val);
    return true;
}

// Detects the float pseudo-literals accepted by the exercise.
bool isFloatPseudoLiteral(const std::string& literal)
{
    return literal == "nanf" || literal == "+inff" || literal == "-inff";
}

// Parses a float literal ending in 'f' and checks float range limits.
bool ScalarConverter::parseFloat(const std::string& literal, float& res)
{
    if (isFloatPseudoLiteral(literal))
        return false;
    
    char *end;
    errno = 0;
    double val = std::strtod(literal.c_str(), &end);
    if (*end != 'f' || *(end + 1) != '\0') return false;
    if (errno == ERANGE || val > FLT_MAX || val < -FLT_MAX) return false;
    res = static_cast<float>(val);
    return true;
}

// Parses a double literal and rejects invalid trailing characters.
bool ScalarConverter::parseDouble(const std::string& literal, double& res)
{
    char *end;
    errno = 0;
    double val = std::strtod(literal.c_str(), &end);
    if (*end != '\0' || errno == ERANGE)
        return false;
    res = static_cast<double>(val);
    return true;
    
}

// Prints all scalar representations starting from a valid char.
void ScalarConverter::printFromChar(char value)
{
    std::cout << "char: '" << value << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(value) << std::endl;
    std::cout << "float: " << static_cast<float>(value) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(value) << ".0" << std::endl;
}

// Prints conversions from a float, handling impossible or non-displayable cases.
void ScalarConverter::printFromFloat(float value)
{
    if (std::isnan(value) || std::isinf(value) || value < 0 || value > 127)
    std::cout << "char: impossible" << std::endl;
    else if (!std::isprint(static_cast<int>(value)))
    std::cout << "char: Non displayable" << std::endl;
    else
    std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
    
    if (std::isnan(value) || std::isinf(value)
    || value > INT_MAX || value < INT_MIN)
    std::cout << "int: impossible" << std::endl;
    else
    std::cout << "int: " << static_cast<int>(value) << std::endl;
    
    std::cout << "float: " << value;
    if (value == static_cast<int>(value))
    std::cout << ".0";
    std::cout << "f" << std::endl;
    
    std::cout << "double: " << static_cast<double>(value);
    if (value == static_cast<int>(value))
    std::cout << ".0";
    std::cout << std::endl;
}

// Prints conversions from an int, including its ASCII char when printable.
void ScalarConverter::printFromInt(int intValue)
{
    if (intValue < 0 || intValue > 127)
    std::cout << "char: impossible" << std::endl;
    else if (!std::isprint(intValue))
    std::cout << "char: Non displayable" << std::endl;
    else
    std::cout << "char: '" << static_cast<char>(intValue) << "'" << std::endl;
    
    std::cout << "int: " << intValue << std::endl;
    
    std::cout << "float: " << static_cast<float>(intValue) << ".0f" << std::endl;
    
    std::cout << "double: " << static_cast<double>(intValue) << ".0" << std::endl;
}

// Prints conversions from a double, handling range and displayability checks.
void ScalarConverter::printFromDouble(double value)
{
    if (std::isnan(value) || std::isinf(value) || value < 0 || value > 127)
        std::cout << "char: impossible" << std::endl;
    else if (!std::isprint(static_cast<int>(value)))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
    
    if (std::isnan(value) || std::isinf(value)
    || value > INT_MAX || value < INT_MIN)
    std::cout << "int: impossible" << std::endl;
    else
    std::cout << "int: " << static_cast<int>(value) << std::endl;
    
    if (value > FLT_MAX || value < -FLT_MAX)
    std::cout << "float: impossible" << std::endl;
    else
    {
        std::cout << "float: " << static_cast<float>(value);
        if (value == static_cast<int>(value))
        std::cout << ".0";
        std::cout << "f" << std::endl;
    }
    
    std::cout << "double: " << value;
    if (value == static_cast<int>(value))
    std::cout << ".0";
    std::cout << std::endl;
}

// Chooses the first matching scalar type and prints all corresponding conversions.
void ScalarConverter::convert(const std::string& literal)
{
    char charValue;
    int intValue;
    float floatValue;
    double doubleValue;

    if (parseChar(literal, charValue))
        printFromChar(charValue);
    else if (parseInt(literal, intValue))
        printFromInt(intValue);
    else if (parseFloat(literal, floatValue))
        printFromFloat(floatValue);
    else if (parseDouble(literal, doubleValue))
        printFromDouble(doubleValue);
    else
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
    }

}

int main(int argc, char* argv[])
{
    if (argc != 2) {
        printUsage();
        return 1;
    }
    ScalarConverter::convert(argv[1]);
    
    return 0;
}
