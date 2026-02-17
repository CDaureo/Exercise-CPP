#pragma once

#include <string>

class Contact {
    private:
        std::string firstName;
        std::string lastName;
        std::string nickname;
        std::string phoneNumber;
        std::string darkestSecret;
        
    public:
        Contact(); // Constructor
        ~Contact(); // Destructor
        
    // Getters
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getNickname() const;
    std::string getPhoneNumber() const;
    std::string getDarkestSecret() const;
    
    // Setters
    void setFirstName(const std::string& firstName);
    void setLastName(const std::string& lastName);
    void setNickname(const std::string& nickname);
    void setPhoneNumber(const std::string& phoneNumber);
    void setDarkestSecret(const std::string& darkestSecret);
};


