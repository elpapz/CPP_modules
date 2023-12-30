#include "ClapTrap.hpp"



int	main(void)
{
	ClapTrap Trap1("Andre");
	ClapTrap Trap2;
	Trap1.dataUpdateDisplay();
	Trap2.dataUpdateDisplay();
	Trap2.attack("Jertrudes");
	Trap1.attack("Ambrosio");
	Trap1.takeDamage(8);
	Trap2.takeDamage(10);
	Trap1.beRepaired(4);
	Trap2.beRepaired(5);
	Trap1.dataUpdateDisplay();
	Trap2.dataUpdateDisplay();
}
