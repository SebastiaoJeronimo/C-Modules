#include "Harl.hpp"

Harl::Harl() : levels{DEBUG, INFO, WARNING, ERROR} , functionArray{&Harl::debug, &Harl::info, &Harl::warning, &Harl::error} {}
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
	//MAKE A SWITCH
}