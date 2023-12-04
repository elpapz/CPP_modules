#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	Zombie *hord = new Zombie[N];
	for(int i = 0; N > i; i++)
	{
			hord[i].setName(name);
	}
	return hord;
}