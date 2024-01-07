#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	int number = 8;
	Animal	*animals[8];

	for(int i = 0; i < number; i++)
	{
		std::cout << "[" << i << "]\n";
		if (i < 4)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
	std::cout << "Animals created!!..... let's move on to delete them!\n";
	for (int i = 0; i < number; i++)
	{
		std::cout << "[" << i << "]\n";
		delete animals[i];
	}
	std::cout << "Animals were deleted!!" << std::endl;
}
