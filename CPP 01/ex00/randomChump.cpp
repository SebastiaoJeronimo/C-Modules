#include "Zombie.hpp"

//stack allocation
void randomChump(std::string name)
{
    Zombie z(name);
    z.announce();
}