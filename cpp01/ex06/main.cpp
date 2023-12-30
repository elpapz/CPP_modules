#include "Harl.hpp"

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		std::string input = av[1];
		Harl	costumer;
		costumer.complain(input);
	}

}
