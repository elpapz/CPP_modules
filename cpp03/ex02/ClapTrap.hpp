
#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <cstdlib>

class ClapTrap
{
	public:
		ClapTrap(std::string _name);
		ClapTrap(const ClapTrap &copy);
		ClapTrap();
		~ClapTrap();
		ClapTrap &operator=(ClapTrap &rhs);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		void dataUpdateDisplay();
		int getLifePoints();
		int getEnergyPoints();
		int getAttackDamage();
		std::string getName();

	protected:
		std::string Name;
		int lifePoints;
		int energyPoints;
		int attackDamage;
};

#endif
