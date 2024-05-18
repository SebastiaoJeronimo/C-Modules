#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
    Zombie *z;
    try
    {
         z = new Zombie(name);
         return z;
    }
    catch (std::bad_alloc& bad_alloc)
    {
        std::cerr << "Failed allocation "<< bad_alloc.what() << "\n";
        delete z;
        return NULL;
    }
}

Zombie *zombieHorde(int N, std::string name)
{
    if (N <= 0)
        return NULL;
    try
    {
        Zombie *horde = new Zombie[N];
        for (int i = 0 ; i < N ; i++)
        {
            horde[i] = Zombie(name);
            horde[i].announce(); //this is to be done on the main function
        }
        return horde;
    }
    catch(std::bad_alloc& bad_alloc)
    {
        std::cerr << "failed zombie horde allocation " << bad_alloc.what() << '\n';
    }
}