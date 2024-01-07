#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "CAT default constructor called\n";
	this->type = "Cat";
}
Cat::~Cat()
{
	std::cout << "CAT destructor called\n";
}
Cat::Cat(const Cat& copy) : Animal(copy)
{
	std::cout << "CAT copy constructor called\n";
}
Cat& Cat::operator=(const Cat& copy)
{
	std::cout << "CAT assignment operator called\n";
	if (this == &copy)
		return (*this);
	this->type = copy.type;
	return (*this);
}
void Cat::makeSound() const
{
	std::cout << "MIIIAAAAAUUUUUUUUUUUU\n";
}
