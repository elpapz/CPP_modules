#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
	public:
		Animal();
		virtual ~Animal();
		Animal(const Animal& copy);
		Animal& operator=(const Animal& copy);
		std::string getType() const;
		virtual void makeSound() const = 0;

	protected:
		std::string type;
};

#endif
