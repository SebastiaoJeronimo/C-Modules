#include "HumanA.hpp"

//Member initializer list -> https://www.youtube.com/watch?v=1nfuYMXjZsA
//. In C++, reference members must be initialized in the initializer list of the constructor because references cannot be reassigned after being initialized.
HumanA::HumanA(const std::string &name, Weapon &weapon) :name(name), weapon(weapon) {}

HumanA::~HumanA() {}

void HumanA::attack() const{ //put the appropriate message
    std::cout << this->name << " attacks with the weapon " << this->weapon.getType() << "\n";
}


