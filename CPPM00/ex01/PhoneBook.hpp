#pragma once

#include "contact.hpp"

class PhoneBook {
	private:
	
		static const int maxContacts = 8;
		Contacto contactos[maxContacts];
		int contactCount;
		int index;
		
		int getTotalContacts() const;
		std::string truncateString(const std::string& str) const;
		void displayContactTable() const;
		void displayContactDetails(int index) const;
		
	public:
		PhoneBook(); // Constructor
		~PhoneBook(); // Destructor
		void addContact(Contacto contacto); // Añadir un contacto
		void displayContacts() const; // Mostrar todos los contactos
		void searchContact(); // Buscar y mostrar un contacto por índice
};