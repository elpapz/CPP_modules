#include "ScalarConverter.hpp"
#include <climits>
#include <limits>
#include <cstdlib>
#include <cmath>
#include <cfloat>
#include <iomanip>


int main(int ac, char **av)
{
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


/*
int main(void)
{
	int i = 0;
	float f = (float)i;
	std::cout << "STANDART FLOAT\n";
	std::cout << INT_MAX << std::endl << INT_MIN << std::endl;

	std::cout << "-FLOATMAX TEST\n";
	std::cout << -INT_MAX << std::endl << INT_MAX << std::endl;
}
*/

