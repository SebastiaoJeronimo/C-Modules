#include "Zombie.hpp"

Zombie::Zombie() {}

Zombie::Zombie(std::string &name)
{
    this->name = name;
}

Zombie::~Zombie() {
    std::cout << "The Zombie: "+ this->getName() + " was destroyed " << "\n";
}

void Zombie::announce() const
{
    std::cout << this->getName() << ": " << ZOMBIE_MSG << "\n";
}

std::string Zombie::getName() const
{
    return this->name;
}