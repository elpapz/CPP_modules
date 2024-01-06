#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FrapTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FrapTrap
{
	public:
		DiamondTrap(std::string Name);
		DiamondTrap();
		~DiamondTrap();
		DiamondTrap(const DiamondTrap& copy);
		DiamondTrap& operator=(const FragTrap& copy);
		void	whoAmI(void);
		using	ScavTrap::attack;

	private:
		std::string Name;
};

#endif
