#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string _name) : Name(_name), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "[CLAPTRAP CONSTRUCTOR WITH PARAMETER CALLED]\n";
}

ClapTrap::ClapTrap() : Name("Default"), hitPoints(10), energyPoints(10), attackDamage(0) {std::cout << "CLAPTRAP DEFAULT CONSTRUCTOR CALLED\n";}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	this->Name = copy.Name;
	this->hitPoints = copy.hitPoints;
	this->energyPoints = copy.energyPoints;
	this->attackDamage = copy.attackDamage;
	std::cout << "[CLAPTRAP COPY CONTRUCTOR CALLED]" << std::endl;
}

ClapTrap::~ClapTrap(){std::cout << "[CLAPTRAP DESCTRUCTOR CALLED]\n";}

ClapTrap& ClapTrap::operator=(ClapTrap &rhs)
{
	std::cout << "[CLAPTRAP ASSIGNMENT OPERATOR OVERLOAD CALLED\n]";
	if (this == &rhs)
		return (*this);
	this->Name = rhs.Name;
	this->hitPoints = rhs.hitPoints;
	this->energyPoints = rhs.energyPoints;
	this->attackDamage = rhs.attackDamage;
	return (*this);
}

void ClapTrap::dataUpdateDisplay()
{
    std::cout << "    NAME -----> " << this->Name << std::endl;
    std::cout << "    HIT POINTS ------> " << this->hitPoints << std::endl;
    std::cout << "    ENERGY POINTS -------> " << this->energyPoints << std::endl;
    std::cout << "    ATTACK DAMAGE -------> " << this->attackDamage << std::endl;
    std::cout << std::endl << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->energyPoints <= 0 || this->hitPoints <= 0)
		{
			std::cout << "You need to get your energy and life points up before attacking again!!" << std::endl;
			return ;
		}
		std::cout << "LOADING THE ATTACK...\n";
	std::cout << " ClapTrap " << this->Name << " attacks " << target << " causing " << this->attackDamage << " points of damage!" << std::endl;
	this->energyPoints -= 1;
}


void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hitPoints <= 0)
	{
		std::cout << "Can't attack who are already DEAD!\n";
		return ;
	}
	std::cout << " ClapTrap " << this->Name << " was attacked and lost " << amount << " hit points " << std::endl;
	this->hitPoints -= amount;
}


void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energyPoints <= 0 || this->hitPoints <= 0)
		{
			std::cout << this->Name << " need's to get your energy and life points up before repairing again!!" << std::endl;
			return ;
		}
	std::cout << "LOADING THE REPAIR...\n";
	std::cout << " ClapTrap " << this->Name << " is repaired and received " << amount << " of hit points" << std::endl;
}


int ClapTrap::getLifePoints()
{
	return (this->hitPoints);
}


int ClapTrap::getEnergyPoints()
{
	return (this->energyPoints);
}


int ClapTrap::getAttackDamage()
{
	return (this->attackDamage);
}


std::string ClapTrap::getName()
{
	return (this->Name);
}