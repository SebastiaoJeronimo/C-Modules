#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
class PhoneBook {
    private:
        Contact contacts[8];
        int counter;
    public:
        ~PhoneBook();
        PhoneBook();
        void addContact(std::string &fistName, std::string &lastName, 
        std::string &nickName, std::string &phoneNumber, const std::string &darkestSecret);
        Contact getContact(int index) const;
        int getCounter() const;
};
#endif