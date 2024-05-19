#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>
#define ZOMBIE_MSG "BraiiiiiiinnnzzzZ..."

class Zombie{

    private:
        std::string name;

    public:
        Zombie();
        Zombie(std::string &name);
        ~Zombie();
        void announce() const;
        std::string getName() const;
};

Zombie *zombieHorde(int N, std::string name);
#endif