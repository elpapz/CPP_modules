#include "Zombie.hpp"

int	main(void)
{
	Zombie	*Hord;
	int N = 5;
	
	while(1)
	{
		std::cout << "Enter a integer that's going to be the number of zombies" << std::endl;
		std::cin >> N;
		if (N <= 0)
		{
			std::cout << "Please put a number bigger then 0" << std::endl;
			std::cin.clear();
		}
		else
			break ;
	}
	std::string	hord_name;
	std::cout << "Now it's time to give your Hord of Zombies one single name:";
	std::cin >> hord_name;
	Hord = zombieHorde(N, hord_name);
	for (int i = 0; i < N; i++)
	{
		Hord[i].announce();
	}
	delete [] Hord;
}
