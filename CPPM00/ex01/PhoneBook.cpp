#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>

PhoneBook::PhoneBook() : contactCount(0) {
    // Constructor por defecto
}
PhoneBook::~PhoneBook() {
    // Destructor
}

// Método privado para calcular el total de Contacts actuales
int PhoneBook::getTotalContacts() const {
    if (contactCount < maxContacts) {
        return contactCount;
    } else {
        return maxContacts;
    }
}

void PhoneBook::addContact(Contact Contact) {
    int index = contactCount % maxContacts;
    Contacts[index] = Contact;
    contactCount++;
}

// Truncar string a 10 caracteres, reemplazando el último con '.' si es más largo
std::string PhoneBook::truncateString(const std::string& str) const {
    if (str.length() > 10) {
        return str.substr(0, 9) + ".";
    }
    return str;
}

// Mostrar tabla de Contacts
void PhoneBook::displayContactTable() const {
    int totalContacts = getTotalContacts();
    
    if (totalContacts == 0) {
        std::cout << "No hay Contacts en la agenda." << std::endl;
        return;
    }
    
    // Encabezado
    std::cout << std::setw(10) << std::right << "Index" << "|";
    std::cout << std::setw(10) << std::right << "First Name" << "|";
    std::cout << std::setw(10) << std::right << "Last Name" << "|";
    std::cout << std::setw(10) << std::right << "Nickname" << std::endl;
    
    // Contacts
    for (int i = 0; i < totalContacts; i++) {
        std::cout << std::setw(10) << std::right << i << "|";
        std::cout << std::setw(10) << std::right << truncateString(Contacts[i].getFirstName()) << "|";
        std::cout << std::setw(10) << std::right << truncateString(Contacts[i].getLastName()) << "|";
        std::cout << std::setw(10) << std::right << truncateString(Contacts[i].getNickname()) << std::endl;
    }
}

// Mostrar detalles de un Contact
void PhoneBook::displayContactDetails(int index) const {
    std::cout << "First Name: " << Contacts[index].getFirstName() << std::endl;
    std::cout << "Last Name: " << Contacts[index].getLastName() << std::endl;
    std::cout << "Nickname: " << Contacts[index].getNickname() << std::endl;
    std::cout << "Phone Number: " << Contacts[index].getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << Contacts[index].getDarkestSecret() << std::endl;
}

void PhoneBook::displayContacts() const {
    int totalContacts = getTotalContacts();
    
    if (totalContacts == 0) {
        std::cout << "No hay Contacts en la agenda." << std::endl;
        return;
    }
    
    for (int i = 0; i < totalContacts; i++) {
        std::cout << "Contact " << (i + 1) << ": " 
                  << Contacts[i].getFirstName() << " " 
                  << Contacts[i].getLastName() << " (" 
                  << Contacts[i].getNickname() << ") - " 
                  << Contacts[i].getPhoneNumber() << std::endl;
    }

}
void PhoneBook::searchContact()
{
    int totalContacts = getTotalContacts();
    
    if (totalContacts == 0) {
        std::cout << "No hay Contacts en la agenda." << std::endl;
        return;
    }
    
    // Mostrar tabla de Contacts
    displayContactTable();
    
    // Pedir índice
    std::cout << "Ingrese el indice del Contact: ";
    std::string input;
    if (!std::getline(std::cin, input)) {
        return; // EOF
    }
    
    // Convertir a int y validar
    std::istringstream iss(input);
    int index;
    if (!(iss >> index) || !(iss.eof())) {
        std::cout << "Indice invalido." << std::endl;
        return;
    }
    
    if (index < 0 || index >= totalContacts) {
        std::cout << "Indice fuera de rango." << std::endl;
        return;
    }
    
    // Mostrar detalles del Contact
    std::cout << std::endl;
    displayContactDetails(index);
}
    