#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"


int main()
{
// Animal Aanimal;
// Animal *andre = new Animal();
const Animal* j = new Dog();
const Animal* i = new Cat();
std::cout << j->getType() << " " << std::endl;
std::cout << i->getType() << " " << std::endl;
i->makeSound(); //will output the cat sound!
j->makeSound();

delete i;
delete j;
}
