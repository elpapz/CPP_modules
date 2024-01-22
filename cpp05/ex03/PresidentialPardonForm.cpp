#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string const& target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << "PRESIDENTIAL CONSTRUCTOR CALLED\n";
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& form) : AForm(form), _target(form._target)
{
	std::cout << "PRESIDENTIAL COPY CONSTRUCTOR CALLED\n";
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PRESIDENTIAL DECONSTRUCTOR CALLED\n";
}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const& form)
{
	if (this == &form)
		return (*this);
	AForm::operator=(form);
	return (*this);
}
bool PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
	try
	{
		if (this->getBoolSign() == true)
		{
			if (executor.getGrade() < this->getExecuteGrade())
				std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox\n";
			else
			{
				std::cout << executor.getName() << " GRADE IS TOO LOW TO EXECUTE PRESIDENTIAL PARDON\n";
				throw AForm::GradeTooLowException();
			}
		}
		else
		{
			std::cout << "PRESIDENTIAL FORM NOT SIGNED\n";
			return false;
		}
	}
	catch(GradeTooLowException &e)
	{
		std::cerr << "[PRESIDENTIAL]Exception :" << e.what() << std::endl;
		return (false);
	}
return (true);
}

std::string const& PresidentialPardonForm::getTarget() const
{
	return (this->_target);
}
