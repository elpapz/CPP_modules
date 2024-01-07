#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "WRONGCAT default constructor called\n";
	this->type = "WrongCat";
}
WrongCat::~WrongCat()
{
	std::cout << "WRONGCAT destructor called\n";
}
WrongCat::WrongCat(const WrongCat& copy) : WrongAnimal(copy)
{
	std::cout << "WRONGCAT copy constructor called\n";
}
WrongCat& WrongCat::operator=(const WrongCat& copy)
{
	std::cout << "WrongCAT assignment operator called\n";
	if (this == &copy)
		return (*this);
	this->type = copy.type;
	return (*this);
}
void WrongCat::makeSound() const
{
	std::cout << "MIIIAAAAAUUUUUUUUUUUU\n";
}
