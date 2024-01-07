#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "BRAIN default constructor called\n";
}
Brain::~Brain()
{
	std::cout << "BRAIN destructor called\n";
}
Brain::Brain(const Brain &copy)
{
	std::cout << "BRAIN copy constructor called\n";
	for (int i = 0; i < 100; i++)
		this->ideas[i] = copy.ideas[i];
}
Brain &Brain::operator=(const Brain &copy)
{
	if(this == &copy)
		return (*this);
	for (int i = 0; i < 100; i++)
		this->ideas[i] = copy.ideas[i];
	return (*this);
}
