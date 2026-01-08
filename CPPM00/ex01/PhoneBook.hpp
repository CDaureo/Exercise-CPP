#pragma once

#include "Contact.hpp"

class PhoneBook {
	private:
	
		static const int maxContacts = 8;
		Contact Contacts[maxContacts];
		int contactCount;
 		
		int getTotalContacts() const;
		std::string truncateString(const std::string& str) const;
		void displayContactTable() const;
		void displayContactDetails(int index) const;
		
	public:
		PhoneBook(); // Constructor
		~PhoneBook(); // Destructor
		void addContact(Contact Contact); // Añadir un Contact
		void displayContacts() const; // Mostrar todos los Contacts
		void searchContact(); // Buscar y mostrar un Contact por índice
};