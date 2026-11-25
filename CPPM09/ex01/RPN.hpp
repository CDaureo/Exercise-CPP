#ifndef RPN_HPP
#define RPN_HPP

#include <list>
#include <stack>
#include <string>

class RPN
{
private:
    // The last operand pushed is the first one popped (LIFO).
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
