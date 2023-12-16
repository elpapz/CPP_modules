#include <iostream>
#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	//*this = copy;
	this->_value = copy.getRawBits();
}

Fixed::~Fixed()
{
	std::cout << "Destructor was called" << std::endl;
}

Fixed& Fixed::operator=(Fixed const &rhs)
{
	std::cout << "The copy assigment operator called" << std::endl;
	if (this != &rhs)
		this->_value = rhs.getRawBits();
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	std::cout << "GetRawBits function called" << std::endl;
	return(this->_value);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "SetRawBits function called" << std::endl;
	this->_value = raw;
}