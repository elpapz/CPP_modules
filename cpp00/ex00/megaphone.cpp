#include <iostream>
#include <cstring>

int	main(int ac, char **av)
{
	if (ac >= 2)
	{
		for(int i = 1; av[i]; i++)
		{
			for(int j = 0; av[i][j]; j++)
				std::cout << char(toupper(av[i][j]));
		}
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << std::endl;
}