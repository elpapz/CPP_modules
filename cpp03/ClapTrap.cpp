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


void ClapTrap::attack(const std::string& target)
{
	
}


void takeDamage(unsigned int amount);


void beRepaired(unsigned int amount);


int getLifePoints();


int getEnergyPoints();


int getAttackDamage();


std::string getName();