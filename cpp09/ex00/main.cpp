#include "BitCoinExchange.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Wrong number of arguments\n";
		return (0);
	}
	try
	{
		BitCoinExchange btc;
		btc.read_files("data.csv", av[1]);

	}
	catch(std::exception &e)
	{
		std::cout << "Fucked up shit bruuuuv\n";
	}
}
