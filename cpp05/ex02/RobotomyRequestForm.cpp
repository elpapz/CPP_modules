#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(std::string const& target) : AForm("RobotomyRequestForm", 72, 45), _target(target) 
{
	std::cout << "ROBOTOMY CONSTRUCTOR CALLED\n";
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& form) : AForm(form), _target(form._target)
{
	std::cout << "ROBOTOMY COPY CONSTRUCTOR CALLED\n";
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "ROBOTOMY DECONSTRUCTOR CALLED\n";
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const& form)
{
	std::cout << "ROBOTOMY ASSIGNMENT OPERATOR CALLED\n";
	if (this == &form)
		return(*this);
	AForm::operator=(form);
	return(*this);
}

bool RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
	std::srand(time(0));	
	try
	{
		if (this->getBoolSign() == true)
		{
			if (executor.getGrade() < this->getExecuteGrade())
			{
				if (random() % 2)
					std::cout << this->_target << " has been robotomized\n";
				else
					std::cout << this->_target << " has failed the robotomization\n";
			}
			else
			{
				std::cout << executor.getName() << " GRADE IS TOO LOW TO EXECUTE REQUESTFORM\n";
				throw AForm::GradeTooLowException();
			}
		}
		else
		{
			std::cout << "ROBOTOMY FORM NOT SIGNED\n";
			return false;
		}
	}
	catch(GradeTooLowException &e)
	{
		std::cerr << "[ROBOTOMY]Exception :" << e.what() << std::endl;
		return false;
	}
	return (true);
}

std::string const&      RobotomyRequestForm::getTarget() const
{
	return (this->_target);
}
