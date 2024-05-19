#include "Zombie.hpp"


//Fazer throws que propagam para a main
//g++ *.cpp *.hpp && valgrind ./a.out
int main()
{
    Zombie *horde;

    if(zombieHorde(0,"blablabla") == NULL)
        std::cout << "This is just to check if its null" << "\n";
    //maybe test if the allocation fails throwing something on the zombieHorde
    if((horde = zombieHorde(3,"zombie")) != NULL)
        for (int i = 0 ; i < 3 ; i++)
            horde[i].announce();
    else std::cout << "allocation failed" << "\n";
    delete [] horde;
}


