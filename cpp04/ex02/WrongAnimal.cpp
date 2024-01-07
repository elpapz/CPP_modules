#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "WRONGANIMAL default constructor called\n";
	this->type = "Animal Default Type";
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WRONGANIMAL destructor called\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy)
{
	std::cout << "WRONGANIMAL copy constructor called\n";
	this->type = copy.type;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& copy)
{
	std::cout << "WRONGANIMAL assignment operator called\n";
	if (this == &copy)
		return (*this);
	this->type = copy.type;
	return (*this);
}

void WrongAnimal::makeSound() const
{
	std::cout << "WRONGANIMAL is making his sound\n";
}

std::string WrongAnimal::getType() const
{
	return (this->type);
}