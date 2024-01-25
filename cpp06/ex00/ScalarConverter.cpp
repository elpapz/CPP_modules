#include "ScalarConverter.hpp"
#include <climits>
#include <limits>
#include <cstdlib>
#include <cmath>
#include <cfloat>
#include <iomanip>

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

bool is_char_valid(std::string input)
{
	if (input.length() != 1 || input[0] <= 32 || input[0] > 126 || input.find_first_of("0123456789") != std::string::npos)
		return false;
	return true;
}

bool isLiteral(std::string input)
{
    if(input == "-inf" || input == "+inf" || input == "-inff" || \
    input == "+inff" || input == "nan")
        return true;
    return false;
}

int its_num(std::string input)
{
	if (is_char_valid(input))
		return (CHAR);
	if (isLiteral(input))
		return (LITERALS);
	int i = 0;
	if (((input[i] >= '0' && input[i] <= '9') || input[i] == '+' || input[i] == '-'))
	{
		if (input.find_first_of("+-", 1) != std::string::npos || input[input.length() - 1] == '.')
			return (ERROR);
		if (input.find_first_not_of("0123456789.f", 1) != std::string::npos)
			return (ERROR);
		if (input.find_first_of(".f") == std::string::npos)
			return (INT);
		else
		{
			if (input.find_first_of('.') == std::string::npos || input.find_first_of('.') != input.find_last_of('.'))
				return (ERROR);
			i = static_cast<int>(input.find_first_of('f'));
			if(i == static_cast<int>(input.find_last_of('f')) && i == static_cast<int>(input.length() -1))
				return (FLOAT);
			 else if (i != static_cast<int>(std::string::npos))
			 	return (ERROR);
			else
				return (DOUBLE);
		}
	}
	else
		return (ERROR);
}

void printLiteral(std::string input)
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    if(input == "-inf" || input == "+inf" || input == "nan")
        std::cout << "float: " << input << "f" << std::endl;
    else
        std::cout << "float: " << input << std::endl;

    if(input == "-inff")
        std::cout << "double: -inf" << std::endl;
    else if(input == "+inff")
        std::cout << "double: +inf" << std::endl;
    else
        std::cout << "double: " << input << std::endl;
}

void print_conversion(std::string input, long double i, int type)
{
	if (type == LITERALS)
	{
		printLiteral(input);
		return ;
	}
	std::cout << "char: ";
	if (i > UCHAR_MAX || i <= 0)
		std::cout << "Non displayable\n";
	else
		std::cout << static_cast<char>(i) << std::endl;
	std::cout << "int: ";
	if (i > INT_MAX || i < INT_MIN)
		std::cout << "Non displayable\n";
	else
		std::cout << static_cast<int>(i) << std::endl;
	std::cout << "float: ";
	if (i < -FLT_MAX || i > FLT_MAX)
		std::cout << "Non displayable\n";
	else if ((i - (int)i) == 0)
		std::cout << i << ".0f\n";
	else
		std::cout << i << "f\n";
	std::cout << "double: ";
	if (i < -DBL_MAX || i > DBL_MAX)
		std::cout << "Non displayable\n";
	else if ((i - (int)i) == 0)
		std::cout << i << ".0\n";
	else
		std::cout << i << std::endl;
}

void ScalarConverter::convert(std::string input)
{

	int type = its_num(input);
	if (type)
	{
		print_conversion(input, std::strtold(input.c_str(), NULL), type);
		return ;
	}
	else
		std::cout << "Wrong input\n";
}
