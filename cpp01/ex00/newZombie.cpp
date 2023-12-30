#include "Zombie.hpp"

Zombie	*newZombie(std::string name)
{
	Zombie	*creat = new Zombie(name);
	return creat;
}
