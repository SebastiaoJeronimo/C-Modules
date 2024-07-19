#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
    if (N <= 0)
        return NULL;
    Zombie *horde;
    try
    {
        horde = new Zombie[N];    //allocates space for a zombie array
        //throw std::bad_alloc(); //just to test see the best practices to raise exceptions
        for (int i = 0 ; i < N ; i++)
            horde[i] = Zombie(name);  
        return horde;
    }
    catch(std::bad_alloc& bad_alloc)
    {
        std::cerr << "failed zombie horde allocation " << bad_alloc.what() << '\n';
        delete[] horde;
        return NULL;
    }
}
