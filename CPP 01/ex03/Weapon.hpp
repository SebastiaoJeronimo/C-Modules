#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon{
    private:
        std::string type;
    public:
        Weapon(); //just made because of HumanA constructor
        Weapon(const std::string &str);
        ~Weapon();
        std::string const & getType() const; //const reference which doesn't allow the user to change the type and the other const is to not allow changing the object
        void setType(const std::string & newWeaponType); 
};

#endif