#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string _name) : Name(_name), lifePoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "Constructor with string parameter called\n";
}

ClapTrap::ClapTrap() : Name("Default"), lifePoints(10), energyPoints(10), attackDamage(0) {std::cout << "Default Constructor called\n";}

ClapTrap::ClapTrap(const ClapTrap &copy) : Name(Name), lifePoints(lifePoints), energyPoints(energyPoints), attackDamage(attackDamage)
{
	std::cout << "Copy contructor called" << std::endl;
}

ClapTrap::~ClapTrap(){std::cout << "Destructor called\n";}

ClapTrap& ClapTrap::operator=(ClapTrap &rhs)
{
	if (this == &rhs)
		return (*this);
	this->Name = rhs.Name;
	this->lifePoints = rhs.lifePoints;
	this->energyPoints = rhs.energyPoints;
	this->attackDamage = rhs.attackDamage;
	return (*this);
}

void ClapTrap::dataUpdateDisplay()
{
    std::cout << "    NAME -----> " << this->Name << std::endl;
    std::cout << "    HIT POINTS ------> " << this->lifePoints << std::endl;
    std::cout << "    ENERGY POINTS -------> " << this->energyPoints << std::endl;
    std::cout << "    ATTACK DAMAGE -------> " << this->attackDamage << std::endl;
    std::cout << std::endl << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->energyPoints <= 0 || this->lifePoints <= 0)
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
	if (this->lifePoints <= 0)
	{
		std::cout << "Can't attack who are already DEAD!\n";
		return ;
	}
	std::cout << " ClapTrap " << this->Name << " was attacked and lost " << amount << " hit points " << std::endl;
	this->lifePoints -= amount;
}


void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energyPoints <= 0 || this->lifePoints <= 0)
		{
			std::cout << this->Name << " need's to get your energy and life points up before repairing again!!" << std::endl;
			return ;
		}
	std::cout << "LOADING THE REPAIR...\n";
	std::cout << " ClapTrap " << this->Name << " is repaired and received " << amount << " of hit points" << std::endl;
}


int ClapTrap::getLifePoints()
{
	return (this->lifePoints);
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