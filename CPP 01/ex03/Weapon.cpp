#include "Weapon.hpp"

Weapon::Weapon() {
    this->type = "";
}

Weapon::Weapon(const std::string &weaponType)
{
    this->type = weaponType;
}   

Weapon::~Weapon() {}

std::string const & Weapon::getType() const
{
    return this->type;
}

void Weapon::setType(const std::string & newWeaponType)
{
    //comment this code block
    //std::cout << "The previous weapon was: " << this->type << "\n";
    //std::cout << "It was replaced by: " << newWeaponType << "\n"; 
    this->type = newWeaponType;
}