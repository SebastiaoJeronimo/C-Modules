#include <iostream>

class Contact
{
    private:
        std::string firstName;
        std::string lastName;
        std::string nickname;
        int phoneNumber;
        std::string darkestSecret;
    public:
        std::string getFirstName(){
            return firstName;
        }
        std::string getLastName(){
            return lastName;
        }
        std::string getNickname(){
            return nickname;
        }
        int getPhoneNumber(){
            return phoneNumber;
        }
        std::string getDarkestSecret(){
            return darkestSecret;
        }
};