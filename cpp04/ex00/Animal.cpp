#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "ANIMAL default constructor called\n";
	this->type = "Animal Default Type";
}

Animal::~Animal()
{
	std::cout << "ANIMAL destructor called\n";
}

Animal::Animal(const Animal& copy)
{
	std::cout << "ANIMAL copy constructor called\n";
	this->type = copy.type;
}

Animal& Animal::operator=(const Animal& copy)
{
	std::cout << "ANIMAL assignment operator called\n";
	if (this == &copy)
		return (*this);
	this->type = copy.type;
	return (*this);
}

void Animal::makeSound() const
{
	std::cout << "ANIMAL is making his sound\n";
}

std::string Animal::getType() const
{
	return (this->type);
}
