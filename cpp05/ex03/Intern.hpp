#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern &cpy);
		Intern &operator=(Intern const &copy);
		~Intern();
		AForm *makeForm(std::string const name, std::string const target);
};

#endif
