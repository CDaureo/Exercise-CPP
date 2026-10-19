#include "MutantStack.hpp"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

static void check(bool condition, const char* message)
{
    if (!condition)
        throw std::runtime_error(message);
}

static void testSubject()
{
    MutantStack<int> mstack;
    std::ostringstream stackOutput;
    mstack.push(5);
    mstack.push(17);
    stackOutput << mstack.top() << '\n';
    mstack.pop();
    stackOutput << mstack.size() << '\n';
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        stackOutput << *it << '\n';
        ++it;
    }
    std::stack<int> s(mstack);
    check(s.size() == 5 && s.top() == 0, "Fallo: copia a std::stack");

    std::list<int> list;
    std::ostringstream listOutput;
    list.push_back(5);
    list.push_back(17);
    listOutput << list.back() << '\n';
    list.pop_back();
    listOutput << list.size() << '\n';
    list.push_back(3);
    list.push_back(5);
    list.push_back(737);
    list.push_back(0);
    for (std::list<int>::iterator lit = list.begin(); lit != list.end(); ++lit)
        listOutput << *lit << '\n';
    check(stackOutput.str() == listOutput.str(), "Fallo: comparacion con list");
    check(stackOutput.str() == "17\n1\n5\n3\n5\n737\n0\n",
        "Fallo: ejemplo del enunciado");
    std::cout << stackOutput.str();
}

static void testIterators()
{
    MutantStack<int> stack;
    const MutantStack<int>& view = stack;
    check(stack.empty() && stack.begin() == stack.end()
        && stack.rbegin() == stack.rend() && view.begin() == view.end()
        && view.rbegin() == view.rend(), "Fallo: pila vacia");
    stack.push(10);
    *stack.begin() = 20;
    check(stack.top() == 20, "Fallo: modificacion por iterador");
    stack.push(30);
    *stack.rbegin() = 40;
    int expected[] = {20, 40};
    int reversed[] = {40, 20};
    check(std::distance(view.begin(), view.end()) == 2
        && std::equal(view.begin(), view.end(), expected),
        "Fallo: iteradores constantes");
    check(std::distance(view.rbegin(), view.rend()) == 2
        && std::equal(view.rbegin(), view.rend(), reversed),
        "Fallo: iteradores inversos constantes");
    check(std::find(stack.begin(), stack.end(), 40) != stack.end(),
        "Fallo: algoritmo STL");
    stack.pop();
    check(stack.top() == 20 && stack.size() == 1, "Fallo: orden LIFO");
    stack.pop();
    check(stack.empty(), "Fallo: vaciado");
}

static void testCopiesAndContainers()
{
    MutantStack<std::string> original;
    original.push("uno");
    original.push("dos");
    MutantStack<std::string> copied(original);
    MutantStack<std::string> assigned;
    assigned.push("anterior");
    assigned = original;
    assigned = assigned;
    original.top() = "cambiado";
    copied.pop();
    check(original.top() == "cambiado" && copied.top() == "uno"
        && assigned.top() == "dos" && assigned.size() == 2,
        "Fallo: copias independientes");

    std::list<int> seed(3, 7);
    MutantStack<int, std::list<int> > listStack(seed);
    check(listStack.size() == 3 && *listStack.begin() == 7,
        "Fallo: contenedor list");
    MutantStack<int, std::vector<int> > vectorStack;
    for (int i = 0; i < 20000; ++i)
        vectorStack.push(i);
    check(vectorStack.size() == 20000 && vectorStack.top() == 19999,
        "Fallo: pila grande");
    int expected = 0;
    for (MutantStack<int, std::vector<int> >::iterator it = vectorStack.begin();
        it != vectorStack.end(); ++it, ++expected)
        check(*it == expected, "Fallo: recorrido de 20000 elementos");
}

int main()
{
    try
    {
        testSubject();
        testIterators();
        testCopiesAndContainers();
        std::cout << "Todas las pruebas de MutantStack superadas." << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
        return 1;
    }
    return 0;
}
