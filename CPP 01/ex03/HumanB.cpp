#include "HumanB.hpp"

HumanB::HumanB(const std::string &name)
{
    this->name = name;
    this->weapon = NULL;
}

HumanB::~HumanB() {}

void HumanB::setWeapon(Weapon &weapon)
{
    this->weapon = &weapon;
}

void HumanB::attack() const{
    if (weapon != NULL) //put the appropriate message
         std::cout << this->name << " attacks with their " << (this->weapon)->getType() << "\n";
    else 
        std::cout << this->name << " does not have a weapon so he attacks with an uppercut\n";
}
