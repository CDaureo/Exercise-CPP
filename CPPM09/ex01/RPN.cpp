#include "RPN.hpp"
#include <limits>
#include <sstream>
#include <stdexcept>

RPN::RPN() {}

RPN::RPN(const RPN &other) : _operands(other._operands) {}

RPN &RPN::operator=(const RPN &other)
{
    if (this != &other)
        _operands = other._operands;
    return *this;
}

RPN::~RPN() {}

int RPN::calculate(int left, int right, char operation)
{
    const int minimum = std::numeric_limits<int>::min();
    const int maximum = std::numeric_limits<int>::max();

    // Comprobamos los límites ANTES de operar: desbordar un int no es seguro.
    if (operation == '+')
    {
        if ((right > 0 && left > maximum - right)
            || (right < 0 && left < minimum - right))
            throw std::overflow_error("integer overflow");
        return left + right;
    }
    if (operation == '-')
    {
        if ((right > 0 && left < minimum + right)
            || (right < 0 && left > maximum + right))
            throw std::overflow_error("integer overflow");
        return left - right;
    }
    if (operation == '*')
    {
        // Dividir los límites permite comprobar el producto sin calcularlo.
        if ((left > 0 && right > 0 && left > maximum / right)
            || (left > 0 && right < 0 && right < minimum / left)
            || (left < 0 && right > 0 && left < minimum / right)
            || (left < 0 && right < 0 && left < maximum / right))
            throw std::overflow_error("integer overflow");
        return left * right;
    }
    if (right == 0)
        throw std::runtime_error("division by zero");
    if (left == minimum && right == -1)
        throw std::overflow_error("integer overflow");
    // División entera con truncamiento hacia cero, también para negativos.
    const int quotient = left / right;
    if (quotient < 0 && left % right != 0
        && ((left < 0 && left % right > 0)
            || (left > 0 && left % right < 0)))
        return quotient + 1;
    return quotient;
}

int RPN::evaluate(const std::string &expression)
{
    // Una nueva evaluación no reutiliza operandos de llamadas anteriores.
    while (!_operands.empty())
        _operands.pop(); // Elimina elemento
    std::istringstream input(expression);
    std::string token;

    while (input >> token)
    {
        // Cada token debe ser un único dígito o un operador binario.
        if (token.size() != 1)
            throw std::runtime_error("invalid token: " + token);
        const char symbol = token[0];
        if (symbol >= '0' && symbol <= '9')
            _operands.push(symbol - '0');
        else
        {
            if (symbol != '+' && symbol != '-' && symbol != '*'
                && symbol != '/')
                throw std::runtime_error("invalid token: " + token);
            if (_operands.size() < 2)
                throw std::runtime_error("not enough operands");
            // En "8 2 -", sale primero 2 (derecha) y después 8 (izquierda). LIFO(Last In, First Out)
            const int right = _operands.top();
            _operands.pop();
            const int left = _operands.top();
            _operands.pop();
            _operands.push(calculate(left, right, symbol));
        }
    }
    // Cero resultados implica entrada vacía; varios, operadores insuficientes.
    if (_operands.size() != 1)
        throw std::runtime_error("expression must produce one result");
    return _operands.top();
}
