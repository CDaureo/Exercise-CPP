/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdaureo- <cdaureo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 11:27:48 by cdaureo-          #+#    #+#             */
/*   Updated: 2026/11/23 15:56:05 by cdaureo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScalarConverter.hpp"
#include <cerrno>
#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) { (void)other; return *this; }

ScalarConverter::~ScalarConverter() {}

namespace
{
    bool isDigit(char value)
    {
        return value >= '0' && value <= '9';
    }

    bool parseChar(const std::string& literal, char& res)
    {
        if (literal.size() == 3 && literal[0] == '\'' && literal[2] == '\'')
            res = literal[1];
        else if (literal.size() == 1 && !isDigit(literal[0]))
            res = literal[0];
        else
            return false;
        return std::isprint(static_cast<unsigned char>(res)) != 0;
    }

    bool isDecimal(const std::string& literal, bool allowFraction)
    {
        std::size_t pos = 0;
        if (literal[pos] == '+' || literal[pos] == '-')
            ++pos;
        const std::size_t start = pos;
        while (isDigit(literal[pos]))
            ++pos;
        bool hasDigits = pos != start;
        if (allowFraction && literal[pos] == '.')
        {
            const std::size_t fractionStart = ++pos;
            while (isDigit(literal[pos]))
                ++pos;
            hasDigits = hasDigits || pos != fractionStart;
        }
        if (!hasDigits)
            return false;
        if (allowFraction && (literal[pos] == 'e' || literal[pos] == 'E'))
        {
            ++pos;
            if (literal[pos] == '+' || literal[pos] == '-')
                ++pos;
            const std::size_t exponentStart = pos;
            while (isDigit(literal[pos]))
                ++pos;
            if (pos == exponentStart)
                return false;
        }
        return pos == literal.size();
    }

    bool parseInt(const std::string& literal, int& res)
    {
        if (!isDecimal(literal, false))
            return false;
        errno = 0;
        const long value = std::strtol(literal.c_str(), NULL, 10);
        if (errno == ERANGE || value < INT_MIN || value > INT_MAX)
            return false;
        res = static_cast<int>(value);
        return true;
    }

    template <typename T>
    bool parsePseudoLiteral(const std::string& literal, T& res)
    {
        if (literal == "nan")
            res = std::numeric_limits<T>::quiet_NaN();
        else if (literal == "+inf")
            res = std::numeric_limits<T>::infinity();
        else if (literal == "-inf")
            res = -std::numeric_limits<T>::infinity();
        else
            return false;
        return true;
    }

    bool parseFloat(const std::string& literal, float& res)
    {
        if (literal.empty() || literal[literal.size() - 1] != 'f')
            return false;
        const std::string number = literal.substr(0, literal.size() - 1);
        if (parsePseudoLiteral(number, res))
            return true;
        if (!isDecimal(number, true))
            return false;
        errno = 0;
        res = ::strtof(number.c_str(), NULL);
        return errno != ERANGE || (res != 0.0f && std::fabs(res) < FLT_MIN);
    }

    bool parseDouble(const std::string& literal, double& res)
    {
        if (parsePseudoLiteral(literal, res))
            return true;
        if (!isDecimal(literal, true))
            return false;
        errno = 0;
        res = std::strtod(literal.c_str(), NULL);
        return errno != ERANGE || (res != 0.0 && std::fabs(res) < DBL_MIN);
    }

    void printChar(double value)
    {
        if (!(value > -1.0 && value < 128.0))
            std::cout << "char: impossible\n";
        else if (!std::isprint(static_cast<int>(value)))
            std::cout << "char: Non displayable\n";
        else
            std::cout << "char: '" << static_cast<char>(value) << "'\n";
    }

    void printInt(double value)
    {
        if (value > static_cast<double>(INT_MIN) - 1.0
            && value < static_cast<double>(INT_MAX) + 1.0)
            std::cout << "int: " << static_cast<int>(value) << '\n';
        else
            std::cout << "int: impossible\n";
    }

    void printDecimal(double value, const char* type, const char* suffix,
                      int precision = 6)
    {
        if (std::isnan(value))
        {
            std::cout << type << ": nan" << suffix << '\n';
            return;
        }
        if (std::isinf(value))
        {
            std::cout << type << ": " << (value < 0 ? "-inf" : "+inf")
                      << suffix << '\n';
            return;
        }
        std::ostringstream stream;
        stream << std::setprecision(precision) << value;
        const std::string number = stream.str();
        std::cout << type << ": " << number;
        if (number.find_first_of(".eE") == std::string::npos)
            std::cout << ".0";
        std::cout << suffix << '\n';
    }

    void printFromChar(char value)
    {
        std::cout << "char: '" << value << "'\n";
        std::cout << "int: " << static_cast<int>(value) << '\n';
        printDecimal(static_cast<float>(value), "float", "f");
        printDecimal(static_cast<double>(value), "double", "");
    }

    void printFromInt(int value)
    {
        printChar(static_cast<double>(value));
        std::cout << "int: " << value << '\n';
        printDecimal(static_cast<float>(value), "float", "f");
        printDecimal(static_cast<double>(value), "double", "", DBL_DIG);
    }

    void printFromFloat(float value)
    {
        printChar(value);
        printInt(value);
        printDecimal(value, "float", "f");
        printDecimal(static_cast<double>(value), "double", "");
    }

    void printFromDouble(double value)
    {
        printChar(value);
        printInt(value);
        if (!std::isinf(value) && (value < -FLT_MAX || value > FLT_MAX))
            std::cout << "float: impossible\n";
        else
            printDecimal(static_cast<float>(value), "float", "f");
        printDecimal(value, "double", "", DBL_DIG);
    }
}

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
        std::cout << "char: impossible\nint: impossible\n"
                  << "float: impossible\ndouble: impossible\n";
}
