#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    std::cout << "[FRAGTRAP DEFAULT CONSTRUCTOR CALLED]\n";
    this->hitPoints = 100;
    this->attackDamage = 30;
    this->energyPoints = 100;
}

FragTrap::FragTrap(std::string _Name) : ClapTrap(_Name)
{
	this->hitPoints = 100;
    this->attackDamage = 30;
    this->energyPoints = 100;
    std::cout << "[FRAGTRAP CONSTRUCTOR WITH PARAMETER CALLED]" << std:: endl;
} 


FragTrap::~FragTrap(){std::cout << " [FRAGTRAP DESTRUCTOR CALLED]\n";}

FragTrap& FragTrap::operator=(const FragTrap& copy)
{
    std::cout << "[FRAGTRAP COPY ASSIGNMENT OPERATOR OVERLOAD CALLED]\n";
    if (this == &copy)
		return (*this);
	this->Name = copy.Name;
	this->hitPoints = copy.hitPoints;
	this->energyPoints = copy.energyPoints;
	this->attackDamage = copy.attackDamage;
	return (*this);
}

void FragTrap::highFiveGuys()
{
	std::cout << "HIGH FIVE EVERYBODY :) :) I AM VERY POSITIVE HA HA HA\n\n";
}
