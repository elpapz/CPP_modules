#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{
	public:
		void announce(void);
		Zombie();
		Zombie(std::string zombie_name);
		~Zombie();

	private:
		std::string name;

};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

#endif
