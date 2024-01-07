#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	public:
		Dog();
		~Dog();
		Dog(const Dog& copy);
		Dog& operator=(const Dog& copy);
		virtual void makeSound() const;
	private:
		Brain *_Brain;
};
#endif
