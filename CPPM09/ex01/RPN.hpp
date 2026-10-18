#ifndef RPN_HPP
#define RPN_HPP

#include <list>
#include <stack>
#include <string>

class RPN
{
private:
    // LIFO: el último operando introducido es el primero que se extrae.
    std::stack<int, std::list<int> > _operands;
    static int calculate(int left, int right, char operation);

public:
    RPN();
    RPN(const RPN &other);
    RPN &operator=(const RPN &other);
    ~RPN();

    int evaluate(const std::string &expression);
};

#endif
