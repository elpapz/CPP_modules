#include "Harl.hpp"

Harl::~Harl(){};

Harl::Harl(){};

void	Harl::debug()
{
	std::cout << "\nPLEASE READ CAREFULY THE COMPLAIN BELLOW:\n\n";
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}
void	Harl::info()
{
	std::cout << "\nPLEASE READ CAREFULY THE COMPLAIN BELLOW:\n\n";
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}
void	Harl::warning()
{
	std::cout << "\nPLEASE READ CAREFULY THE COMPLAIN BELLOW:\n\n";
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}
void	Harl::error()
{
	std::cout << "\nPLEASE READ CAREFULY THE COMPLAIN BELLOW:\n\n";
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level)
{


	std::string	errors[4] = {"DEBUG", "ERROR", "WARNING", "INFO"};
	void	(Harl::*function[4])(void) = {&debug, &error, &warning, &info};
	for (int i = 0; i < 4; i++)
	{
		if (level.compare(errors[i]) == 0)
		(this->*function[i])();
	}
}
