#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class Weapon
{
	public:
		Weapon(std::string _type);
		~Weapon();
		Weapon();
		const	std::string& getType(void);
		void	setType(std::string _type);
	private:
		std::string	type;	
};

#endif