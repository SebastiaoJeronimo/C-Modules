#include "Contact.hpp"

Contact::~Contact(){}

Contact::Contact(){
       this->firstName = "";
       this->lastName = "";
       this->nickname = "";
       this->phoneNumber = "";
       this->darkestSecret = "";
}

Contact::Contact(std::string &first, std::string &last, std::string &nick, 
    std::string &phone,  const std::string &secret){


       this->firstName = first;
       this->lastName = last;
       this->nickname = nick;
       this->phoneNumber = phone;
       this->darkestSecret = secret;
}


std::string Contact::getFirstName() const{
       return this->firstName;
}
std::string Contact::getLastName() const{
       return this->lastName;
}
std::string Contact::getNickname() const{
       return this->nickname;
}
std::string Contact::getPhoneNumber() const{
       return this->phoneNumber;
}
std::string Contact::getDarkestSecret() const{
       return this->darkestSecret;
}
