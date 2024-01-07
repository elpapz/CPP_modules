#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
	public:
		Brain();
		~Brain();
		Brain(const Brain &copy);
		Brain &operator=(const Brain &copy);
	private:
		std::string ideas[100];
};

#endif