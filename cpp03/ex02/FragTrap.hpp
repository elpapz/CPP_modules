#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap(std::string Name);
		FragTrap();
		~FragTrap();
		FragTrap(const FragTrap& copy);
		void	highFiveGuys(void);
		FragTrap& operator=(const FragTrap& copy);
};

#endif
