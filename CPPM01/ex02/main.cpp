#include <string> 
#include <iostream>

int main(void)
{
    //&text == stringPTR == &stringREF
    std::string text = "HI THIS IS BRAIN"; // Variable objeto
    std::string* stringPTR = &text; // Puntero: puede cambiar a qué apunta y puede ser nullptr.
    std::string& stringREF = text; //Referencia: fija al objeto desde su creación.

    std::cout << "Dirección de la variable: " << &text << std::endl;
    std::cout << "Dirección en stringPTR: " << stringPTR << std::endl;
    std::cout << "Dirección en stringREF: " << &stringREF << std::endl;

    std::cout << "Valor de la variable: " << text << std::endl;
    std::cout << "Valor apuntado por stringPTR: " << *stringPTR << std::endl;
    std::cout << "Valor referenciado por stringREF: " << stringREF << std::endl;

    return 0;
}
