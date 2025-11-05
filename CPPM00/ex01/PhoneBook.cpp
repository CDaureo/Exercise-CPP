#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>

PhoneBook::PhoneBook() : contactCount(0), index(0) {
    // Constructor por defecto
}
PhoneBook::~PhoneBook() {
    // Destructor
}

// Método privado para calcular el total de contactos actuales
int PhoneBook::getTotalContacts() const {
    if (contactCount < maxContacts) {
        return contactCount;
    } else {
        return maxContacts;
    }
}

void PhoneBook::addContact(Contacto contacto) {
    int index = contactCount % maxContacts;
    contactos[index] = contacto;
    contactCount++;
}

// Truncar string a 10 caracteres, reemplazando el último con '.' si es más largo
std::string PhoneBook::truncateString(const std::string& str) const {
    if (str.length() > 10) {
        return str.substr(0, 9) + ".";
    }
    return str;
}

// Mostrar tabla de contactos
void PhoneBook::displayContactTable() const {
    int totalContacts = getTotalContacts();
    
    if (totalContacts == 0) {
        std::cout << "No hay contactos en la agenda." << std::endl;
        return;
    }
    
    // Encabezado
    std::cout << std::setw(10) << std::right << "Index" << "|";
    std::cout << std::setw(10) << std::right << "First Name" << "|";
    std::cout << std::setw(10) << std::right << "Last Name" << "|";
    std::cout << std::setw(10) << std::right << "Nickname" << std::endl;
    
    // Contactos
    for (int i = 0; i < totalContacts; i++) {
        std::cout << std::setw(10) << std::right << i << "|";
        std::cout << std::setw(10) << std::right << truncateString(contactos[i].getFirstName()) << "|";
        std::cout << std::setw(10) << std::right << truncateString(contactos[i].getLastName()) << "|";
        std::cout << std::setw(10) << std::right << truncateString(contactos[i].getNickname()) << std::endl;
    }
}

// Mostrar detalles de un contacto
void PhoneBook::displayContactDetails(int index) const {
    std::cout << "First Name: " << contactos[index].getFirstName() << std::endl;
    std::cout << "Last Name: " << contactos[index].getLastName() << std::endl;
    std::cout << "Nickname: " << contactos[index].getNickname() << std::endl;
    std::cout << "Phone Number: " << contactos[index].getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << contactos[index].getDarkestSecret() << std::endl;
}

void PhoneBook::displayContacts() const {
    int totalContacts = getTotalContacts();
    
    if (totalContacts == 0) {
        std::cout << "No hay contactos en la agenda." << std::endl;
        return;
    }
    
    for (int i = 0; i < totalContacts; i++) {
        std::cout << "Contacto " << (i + 1) << ": " 
                  << contactos[i].getFirstName() << " " 
                  << contactos[i].getLastName() << " (" 
                  << contactos[i].getNickname() << ") - " 
                  << contactos[i].getPhoneNumber() << std::endl;
    }

}
void PhoneBook::searchContact()
{
    int totalContacts = getTotalContacts();
    
    if (totalContacts == 0) {
        std::cout << "No hay contactos en la agenda." << std::endl;
        return;
    }
    
    // Mostrar tabla de contactos
    displayContactTable();
    
    // Pedir índice
    std::cout << "Ingrese el indice del contacto: ";
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
    
    // Mostrar detalles del contacto
    std::cout << std::endl;
    displayContactDetails(index);
}
    