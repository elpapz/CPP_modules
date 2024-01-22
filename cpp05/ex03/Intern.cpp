#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <cstdlib>


Intern::Intern()
{
	std::cout << "INTERN DEFAULT CONSTRUCTOR CALLED\n";
}
Intern::Intern(const Intern &copy)
{
	std::cout << "INTERN COPY CONSTRUCTOR CALLED\n";
	*this = copy;
}
Intern& Intern::operator=(Intern const &cpy)
{
	(void)cpy;
	return (*this);
}
Intern::~Intern()
{
	std::cout << "INTERN DESTRUCTOR CALLED \n";
}
AForm *Intern::makeForm(std::string const name, std::string const target)
{
	AForm *final_form = NULL;
	std::string FormNames[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	AForm *Forms[] = {new PresidentialPardonForm(target), new RobotomyRequestForm(target), new ShrubberyCreationForm(target)};
	for(int i = 0; i < 3; i++)
	{
		if (name == FormNames[i])
			final_form = Forms[i];
		else
			delete Forms[i];
	}
	if (final_form == NULL)
		std::cout << "Error, check if the Form name are the right one!\n";
return (final_form);
}
