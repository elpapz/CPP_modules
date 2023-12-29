#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
	public:
		Animal();
		~Animal();
		Animal(const Animal& copy);
		Animal& operator=(const Animal& copy);
		void makeSound();
	
	protected:
		std::string type;
};

#endif