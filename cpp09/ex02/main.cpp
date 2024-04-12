#include "PmergeMe.hpp"

void parse_input(int ac, char **av)
{
	(void)ac;
	 if (ac < 2)
		throw PmergeMe::wrongInput();
	for (int i = 1; i < ac; i++)
	{
		if (std::atol(av[i]) > (long)INT_MAX || std::atol(av[i]) < 0)
			throw PmergeMe::wrongInput();
		for (int j = 0; av[i][j]; j++)
		{
			if (!std::isdigit(av[i][j]))
				throw PmergeMe::wrongInput();			
		}
	}
}

void displayRawInput(int ac, char **av)
{
		std::cout << "Before: ";
		for (int i = 1; i < ac; i++)
			std::cout << av[i] << " ";
		std::cout << std::endl;
}

int main(int argc, char **argv)
{
	try
	{
		parse_input(argc, argv);
		displayRawInput(argc, argv);
		PmergeMe mergeMe;
		mergeMe.startSorting(argc, argv);
		
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return 1;
	}
	return 0;
}


