#include <iostream>
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed::Fixed(const int num)
{
	std::cout << "Int constructor called" << std::endl;
	this->_value = num * (1 << this->_bits);
}

Fixed::Fixed(const float num)
{
	std::cout << "Float constructor called" << std::endl;
	float temp = num * (1 << this->_bits);
	this->_value = roundf(temp);
}

Fixed::~Fixed()
{
	std::cout << "Destructor was called" << std::endl;
}

Fixed& Fixed::operator=(Fixed const &rhs)
{
	std::cout << "Copy assigment operator called" << std::endl;
	if (this != &rhs)
		this->_value = rhs.getRawBits();
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	return(this->_value);
}

void Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

float Fixed::toFloat(void) const
{
	return ((float)this->_value / (float)(1 << Fixed::_bits));
}

int Fixed::toInt(void) const
{
	return (this->_value / (1 << this->_bits));
}

std::ostream& operator<<(std::ostream& stream, Fixed const& obj)
{
	stream << obj.toFloat();
	return (stream);
}
