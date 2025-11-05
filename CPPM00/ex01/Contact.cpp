#include "Contact.hpp"

Contacto::Contacto() : firstName(""), lastName(""), nickname(""), 
                       phoneNumber(""), darkestSecret("") {
    // Constructor por defecto
}

Contacto::~Contacto() {
    // Destructor
}

// Getters
std::string Contacto::getFirstName() const {
    return firstName;
}

std::string Contacto::getLastName() const {
    return lastName;
}

std::string Contacto::getNickname() const {
    return nickname;
}

std::string Contacto::getPhoneNumber() const {
    return phoneNumber;
}

std::string Contacto::getDarkestSecret() const {
    return darkestSecret;
}

// Setters
void Contacto::setFirstName(const std::string& firstName) {
    this->firstName = firstName;
}

void Contacto::setLastName(const std::string& lastName) {
    this->lastName = lastName;
}

void Contacto::setNickname(const std::string& nickname) {
    this->nickname = nickname;
}

void Contacto::setPhoneNumber(const std::string& phoneNumber) {
    this->phoneNumber = phoneNumber;
}

void Contacto::setDarkestSecret(const std::string& darkestSecret) {
    this->darkestSecret = darkestSecret;
}
