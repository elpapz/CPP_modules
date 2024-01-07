#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "DOG default constructor called\n";
	this->type = "Dog";
	this->_Brain = new Brain();
}

Dog::~Dog()
{
	std::cout <<"DOG deconstructor called \n";
	delete this->_Brain;
}

Dog::Dog(const Dog& copy) : Animal(copy)
{
	std::cout << "DOG copy constructor called\n";
	this->_Brain = copy._Brain;
}

Dog& Dog::operator=(const Dog& copy)
{
	if (this == &copy)
		return (*this);
	this->type = copy.type;
	this->_Brain = copy._Brain;
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "AUFFF AUFFF AUFFF AUFFF\n";
}
