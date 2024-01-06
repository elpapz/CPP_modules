#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    std::cout << "[SCAVTRAP DEFAULT CONSTRUCTOR CALLED]\n";
    this->hitPoints = 100;
    this->attackDamage = 20;
    this->energyPoints = 50;
}

ScavTrap::ScavTrap(std::string _Name) : ClapTrap(_Name)
{
	this->hitPoints = 100;
    this->attackDamage = 20;
    this->energyPoints = 50;
    std::cout << "[SCAVTRAP CONSTRUCTOR WITH PARAMETER CALLED]" << std:: endl;
} 


ScavTrap::~ScavTrap(){std::cout << " [SCAVTRAP DESTRUCTOR CALLED]\n";}

void ScavTrap::guardGate(){std::cout << "ScavTrap is in Gate keeper mode now" << std::endl;}

void ScavTrap::attack(const std::string& target)
{
    if (this->energyPoints <= 0 || this->hitPoints <= 0)
		{
			std::cout << "You need to get your energy and life points up before attacking again!!" << std::endl;
			return ;
		}
		std::cout << "LOADING THE ATTACK...\n";
	std::cout << " [SCAVTRAP] " << this->Name << " attacks " << target << " causing " << this->attackDamage << " points of damage!" << std::endl;
	this->energyPoints -= 1;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& copy)
{
    std::cout << "[SCAVTRAP COPY ASSIGNMENT OPERATOR OVERLOAD CALLED]\n";
    if (this == &copy)
		return (*this);
	this->Name = copy.Name;
	this->hitPoints = copy.hitPoints;
	this->energyPoints = copy.energyPoints;
	this->attackDamage = copy.attackDamage;
	return (*this);
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy)
{
	std::cout << "[SCAVTRAP COPY CONTRUCTOR CALLED]" << std::endl;
}