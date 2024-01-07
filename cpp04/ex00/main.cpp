#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

// int main()
// {
// 	Animal *andre = new Animal();
// 	std::cout << andre->getType() << " " << std::endl;
// }

int main()
{
const Animal* meta = new Animal();
const Animal* j = new Dog();
const Animal* i = new Cat();
std::cout << j->getType() << " " << std::endl;
std::cout << i->getType() << " " << std::endl;
i->makeSound(); //will output the cat sound!
j->makeSound();
meta->makeSound();

delete meta;
delete i;
delete j;
std::cout << "\n\n" << "NOW... LET'S SEE THE WRONG EXAMPLES\n\n";

const WrongAnimal* meta2 = new WrongAnimal();
const WrongAnimal* i2 = new WrongCat();
std::cout << i2->getType() << " " << std::endl;
std::cout << meta2->getType() << " " << std::endl;
i2->makeSound(); //will output the cat sound!
meta2->makeSound();

delete meta2;
delete i2;

return 0;
}