#include "Harl.hpp"

Harl::Harl() {}
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

int Harl::getLevelValue(std::string level)
{
	if (level == DEBUG)
		return 1;
	if (level == WARNING)
		return 2;
	if (level == INFO)
		return 3;
	if (level == ERROR)
		return 4;
	return 0;
}


void Harl::complain(std::string level) {
	//MAKE A SWITCH
	switch (getLevelValue(level))
	{
	case 1:
		debug();
		break;
	case 2:
		warning();
		break;
	case 3:
		info();
		break;
	case 4:
		error();
		break;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]" << "\n";
		break;
	}
}