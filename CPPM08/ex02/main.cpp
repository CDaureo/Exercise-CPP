#include "MutantStack.hpp"
#include <algorithm>
#include <deque>
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
    const int topBeforePop = mstack.top();
    mstack.pop();
    const std::stack<int>::size_type sizeAfterPop = mstack.size();
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
        stackOutput << ' ' << *it;
        ++it;
    }
    std::stack<int> s(mstack);
    check(s.size() == 5 && s.top() == 0, "Fallo: copia a std::stack");

    std::list<int> list;
    std::ostringstream listOutput;
    list.push_back(5);
    list.push_back(17);
    check(topBeforePop == list.back() && topBeforePop == 17,
        "Fallo: cima antes de pop");
    list.pop_back();
    check(sizeAfterPop == list.size() && sizeAfterPop == 1,
        "Fallo: tamano despues de pop");
    list.push_back(3);
    list.push_back(5);
    list.push_back(737);
    list.push_back(0);
    for (std::list<int>::iterator lit = list.begin(); lit != list.end(); ++lit)
        listOutput << ' ' << *lit;
    check(stackOutput.str() == listOutput.str(), "Fallo: comparacion con list");
    check(stackOutput.str() == " 5 3 5 737 0",
        "Fallo: ejemplo del enunciado");
    std::cout << "Ejemplo del enunciado" << std::endl;
    std::cout << "Cima tras insertar 5 y 17 = " << topBeforePop << std::endl;
    std::cout << "Elementos tras quitar el 17 = " << sizeAfterPop << std::endl;
    std::cout << "Recorrido de la base a la cima =" << stackOutput.str()
        << std::endl;
    std::cout << "El recorrido coincide con std::list." << std::endl;
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

static void testCopies()
{
    MutantStack<std::string> original;
    original.push("uno");
    original.push("dos");
    MutantStack<std::string> copied(original);
    MutantStack<std::string> assigned;
    assigned.push("anterior");
    assigned = original;
    const MutantStack<std::string>& sameStack = assigned;
    assigned = sameStack;
    original.top() = "cambiado";
    copied.pop();
    check(original.top() == "cambiado" && copied.top() == "uno"
        && assigned.top() == "dos" && assigned.size() == 2,
        "Fallo: copias independientes");
}

template <typename Container>
static void testContainer(const char* name)
{
    MutantStack<int, Container> stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);

    const int expected[] = {10, 20, 30};
    check(std::distance(stack.begin(), stack.end()) == 3
        && std::equal(stack.begin(), stack.end(), expected),
        "Fallo: recorrido del contenedor");
    check(stack.top() == 30, "Fallo: cima antes de pop");
    stack.pop();
    check(stack.size() == 2 && stack.top() == 20, "Fallo: cima despues de pop");

    std::cout << name << " OK (recorrido 10 20 30, cima tras pop = "
        << stack.top() << ")" << std::endl;
}

int main()
{
    try
    {
        testSubject();
        testIterators();
        testCopies();
        testContainer<std::deque<int> >("deque");
        testContainer<std::vector<int> >("vector");
        testContainer<std::list<int> >("list");
        std::cout << "Todas las pruebas de MutantStack." << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
        return 1;
    }
    return 0;
}
