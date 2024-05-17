#include "Zombie.hpp"

//https://stackoverflow.com/questions/7277637/new-stdnothrow-vs-new-within-a-try-catch-block
Zombie* newZombie(std::string name) //RAII doubt this is not the best way to do it
{
    Zombie *z;
    try
    {
         z = new Zombie(name);
         return z;
    }
    catch (std::bad_alloc& bad_alloc)
    {
        std::cout << "Failed allocation "<< bad_alloc.what() << "\n";
        delete z;
        return NULL;
    }
}

/* THIS IS WRONG 
 you should dynamically allocate the Zombie object using new. This will create the object on the heap, and it will persist until you explicitly delete it.
Zombie* newZombie(std::string &name)
{
    return &Zombie(name);
}
*/

//allocate memory when
// want to keep values out of scope
// to not waste space with static location
// when you statically allocate space on a static variable and you will need to double that space


/*
#include <iostream>
#include <new>
 
int main()
{
    try
    {
        while (true)
        {
            new int[100000000ul];   // throwing overload
        }
    }
    catch (const std::bad_alloc& e)
    {
        std::cout << e.what() << '\n';
    }
 
    while (true)
    {
        int* p = new(std::nothrow) int[100000000ul]; // non-throwing overload
        if (p == nullptr)
        {
            std::cout << "Allocation returned nullptr\n";
            break;
        }
    }
}
*/