#include "Harl.hpp"

//extended initializer lists are only available on the c++ 11 
//Harl::Harl() : levels{DEBUG, INFO, WARNING, ERROR} , functionArray{&Harl::debug, &Harl::info, &Harl::warning, &Harl::error} {}

Harl::Harl() {
    levels[0] = DEBUG;
    levels[1] = INFO;
    levels[2] = WARNING;
    levels[3] = ERROR;

    functionArray[0] = &Harl::debug;
    functionArray[1] = &Harl::info;
    functionArray[2] = &Harl::warning;
    functionArray[3] = &Harl::error;
}

Harl::~Harl() {}

void Harl::debug( void )
{
	std::cout << "I love having extra bacon for my cheese burger. I really do!" << "\n";
}
void Harl::info( void )
{
	std::cout << "Adding extra bacon costs more money." << "\n";
}
void Harl::warning( void )
{
	std::cout << "I think I deserve to have some extra bacon for free."<< "\n";
}
void Harl::error( void )
{
	std::cout << "This is unacceptable! I want to speak to the manager now."<< "\n";
}

void Harl::complain(std::string level) {
    for (int i = 0 ; i < 4 ; i++)
        if (levels[i] == level)
            return (this->*functionArray[i])(); //have to specify which object youre calling the function on with this
    std::cout << "[ Probably complaining about insignificant problems ]" << "\n";
}