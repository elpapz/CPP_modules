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
	delete j;
	delete i;

	const Animal *original = new Dog();
	const Animal *pointToOriginal = original;

	std::cout << pointToOriginal->getType() << std::endl;
	pointToOriginal->makeSound();

	const Dog *otherOriginal = new Dog();
	const Dog *newCopy = new Dog(*otherOriginal);

	std::cout << otherOriginal->getType() << std::endl;
	otherOriginal->makeSound();

	std::cout << newCopy->getType() << std::endl;
	newCopy->makeSound();

	delete original;
	delete otherOriginal;
	delete newCopy;

	titleHeader("WRONG ANIMAL TEST");
	const WrongAnimal* cat = new WrongCat();
	cat->makeSound();
	delete cat;
}