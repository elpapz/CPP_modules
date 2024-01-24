#include <climits>
#include <limits>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	// std::string str = "andre";
	// std::cout << str.length() << std::endl << str.size() << std::endl << str.find_first_of('e') << std::endl;
	if (ac != 2)
	{
		std::cout << "Wrong number of arguments\n";
		return (0);
	}
	if (!av[1][0])
	{
		std::cout << "Empty argument :/\n";
		return (0);
	}
	std::string input = av[1];
	ScalarConverter::convert(input);
}
