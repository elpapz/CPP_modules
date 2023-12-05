#include "HumanB.hpp"
#include "Weapon.hpp"

//HumanA::HumanA(std::string name, Weapon &_weapon) : _name(name), _weapon(_weapon){}

HumanB::HumanB(std::string name)
{
	this->_name = name;
}

HumanB::~HumanB(){}

void	HumanB::setWeapon(Weapon& weapon)
{
	this->_weapon = &weapon;
}

void	HumanB::attack()
{

	std::cout << this->_name << " attacks with his " << this->_weapon->getType() << std::endl;
}