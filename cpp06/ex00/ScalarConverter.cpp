#include "ScalarConverter.hpp"
#include <climits>
#include <limits>
#include <cstdlib>
#include <cmath>


ScalarConverter::ScalarConverter(){}
ScalarConverter::~ScalarConverter(){}
ScalarConverter::ScalarConverter(const ScalarConverter& copy)
{
	(void)copy;
}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& copy)
{
	(void)copy;
	return (*this);
}

int its_num(std::string input)
{
	unsigned long i = 0;
	if (((input[i] >= '0' && input[i] <= '9') || input[i] == '+' || input[i] == '-'))
	{
		if (input.find_first_of("+-", 1) != std::string::npos || input[input.length() - 1] == '.')
			return (0);
		if (input.find_first_not_of("0123456789.f", 1) != std::string::npos)
			return (0);
		if (input.find_first_of(".f") == std::string::npos)
			return (1);
		else
		{
			if (input.find_first_of('.') == std::string::npos || input.find_first_of('.') != input.find_last_of('.'))
				return (0);
			i = input.find_first_of('f');
			if(i == input.find_last_of('f') && i == input.length() -1)
				return (3);
			 else if (i != std::string::npos)
			 	return (0);
			else
				return (2);
			
		}		
	}
	else
		return (0);
}

void ScalarConverter::convert(std::string input)
{
	int type = its_num(input);
	if (type)
	{
		std::cout << type << std::endl;
		return ;
	}
	else
		std::cout << "It must be a char!!!\n" << type << std::endl;
}