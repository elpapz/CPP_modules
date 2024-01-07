#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "CAT default constructor called\n";
	this->type = "Cat";
	this->_Brain = new Brain();
}
Cat::~Cat()
{
	std::cout << "CAT destructor called\n";
	delete this->_Brain;
}
Cat::Cat(const Cat& copy) : Animal(copy)
{
	std::cout << "CAT copy constructor called\n";
	this->_Brain = copy._Brain;
}
Cat& Cat::operator=(const Cat& copy)
{
	std::cout << "CAT assignment operator called\n";
	if (this == &copy)
		return (*this);
	this->type = copy.type;
	this->_Brain = copy._Brain;
	return (*this);
}
void Cat::makeSound() const
{
	std::cout << "MIIIAAAAAUUUUUUUUUUUU\n";
}
