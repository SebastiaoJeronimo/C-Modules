#include "PhoneBook.hpp"

PhoneBook::~PhoneBook(){}

PhoneBook::PhoneBook(){
     this->counter = 0;
}

void PhoneBook::addContact(std::string &fistName, std::string &lastName, 
         std::string &nickname,  std::string &phoneNumber, const std::string &darkestSecret){
     if (counter < 8)    
     {
          this->contacts[counter] = Contact(fistName, lastName, nickname, phoneNumber, darkestSecret);
          counter++;
     }
     else
     {
          for(int i = 0; i < 7; i++)
               this->contacts[i] = this->contacts[i + 1];
          this->contacts[7] = Contact(fistName, lastName, nickname, phoneNumber, darkestSecret);
     }
}

Contact PhoneBook::getContact(int contactIndex) const {
     return this->contacts[contactIndex];
}

int PhoneBook::getCounter() const {
     return this->counter;
}