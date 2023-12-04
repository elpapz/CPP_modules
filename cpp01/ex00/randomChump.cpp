#include "Zombie.hpp"

void	randomChump(std::string name)
{
	Zombie creat = Zombie(name);
	creat.announce();
}