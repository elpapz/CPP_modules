#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "DOG default constructor called\n";
	this->type = "Dog";
}
Dog::~Dog()
{
	std::cout <<"DOG deconstructor called \n";
}
Dog::Dog(const Dog& copy) : Animal(copy)
{
	std::cout << "DOG copy constructor called\n";
}
Dog& Dog::operator=(const Dog& copy)
{
	if (this == &copy)
		return (*this);
	this->type = copy.type;
	return (*this);
	
}
void Dog::makeSound() const
{
	std::cout << "AUFFF AUFFF AUFFF AUFFF\n";
}
