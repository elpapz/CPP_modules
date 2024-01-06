
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
		int hitPoints;
		int energyPoints;
		int attackDamage;
};

#endif

/*
#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <cstdlib>

class	ClapTrap
{
	private:
		std::string	_name;
		int			_hitPoints;
		int			_energyPoints;
		int			_attackDamage;

	public:
		// Constructors and destructor
		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(ClapTrap const &copy);
		~ClapTrap(void);

		// Operators
		ClapTrap	&operator=(ClapTrap const &copy);

		// Get functions
		std::string	getName(void) const;
		int			getHitPoints(void) const;
		int			getEnergyPoints(void) const;
		int			getAttackDamage(void) const;

		// Member functions
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		bool	isGameOver(void);
};

std::ostream	&operator<<(std::ostream &out, ClapTrap const &trap);

#endif
*/
