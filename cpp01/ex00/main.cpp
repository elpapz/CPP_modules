#include "Zombie.hpp"

int	main(void)
{
	Zombie *heap_zombie;
	std::string stack_zombie_name;
	std::string heap_zombie_name;

	std::cout << "Enter your first zombie name: ";
	std::getline(std::cin, stack_zombie_name);
	std::cout <<  std::endl << "Enter your second zombie name: ";
	std::getline(std::cin, heap_zombie_name);
	heap_zombie = newZombie(heap_zombie_name);
	heap_zombie->announce();
	delete heap_zombie;
	randomChump(stack_zombie_name);
}
