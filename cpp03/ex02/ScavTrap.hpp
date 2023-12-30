#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

//#include <iostream>
//# include <cstdlib>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(std::string _Name);
		~ScavTrap();
		void guardGate();
		void attack(const std::string& target);
		ScavTrap& operator=(const ScavTrap& copy);
};

#endif
