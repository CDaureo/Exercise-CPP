#include "PhoneBook.hpp"
#include <iostream>
#include <string>

bool readField(const std::string& prompt, std::string& field) {
    while (true) {
        std::cout << prompt;
        if (!std::getline(std::cin, field)) {
            return false; // EOF (Ctrl+D)
        }
        if (!field.empty()) {
            return true; // Campo válido
        }
        std::cout << "Campo vacio. Reintente." << std::endl;
    }
}

void handleAddContact(PhoneBook& phoneBook) {
    Contacto newContact;
    std::string firstName, lastName, nickname, phoneNumber, darkestSecret;
    
    if (!readField("First Name: ", firstName)) return;
    if (!readField("Last Name: ", lastName)) return;
    if (!readField("Nickname: ", nickname)) return;
    if (!readField("Phone Number: ", phoneNumber)) return;
    if (!readField("Darkest Secret: ", darkestSecret)) return;
    
    newContact.setFirstName(firstName);
    newContact.setLastName(lastName);
    newContact.setNickname(nickname);
    newContact.setPhoneNumber(phoneNumber);
    newContact.setDarkestSecret(darkestSecret);
    phoneBook.addContact(newContact);
    std::cout << "Contacto agregado exitosamente." << std::endl;
}

int main()
{   
    PhoneBook phoneBook;
    std::string input = "";
    
    while (input != "EXIT")
    {   
        std::cout << "Introduce comando (ADD, SEARCH, EXIT): ";
        
        if (!std::getline(std::cin, input)) {
            std::cout << std::endl;
            break;
        }
        
        if (input == "ADD")
        {
            handleAddContact(phoneBook);
        }
        else if (input == "SEARCH")
        {
            phoneBook.searchContact();
        }
        else if (input != "EXIT")
            std::cout << "COMANDO NO ENCONTRADO" << std::endl;
    }
    return 0;
}
