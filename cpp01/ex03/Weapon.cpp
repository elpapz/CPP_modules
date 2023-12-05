#include "Weapon.hpp"

Weapon::Weapon(std::string _type)
{
	this->type = _type;
}

Weapon::Weapon(){}

Weapon::~Weapon(){}

const	std::string &Weapon::getType(void)
{
	return (this->type);
}

void	Weapon::setType(std::string _type)
{
	this->type = _type;
}