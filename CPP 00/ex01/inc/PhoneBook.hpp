#include "Contact.hpp"

class PhoneBook {
    private:
        Contact contacts[8];
        int counter;
    public:
        ~PhoneBook();
        PhoneBook();
        void addContact();
        Contact getContact(int index) const;
};