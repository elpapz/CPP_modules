#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : Name("Bureaucrat Default Name"), _grade(42)
{
	std::cout << "BUREAUCRAT DEFAULT CONSTRUCTOR CALLED" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : Name(name), _grade(grade)
{
	std::cout << "BUREAUCRAT DOUBLE ARGUMENT CONSTRUCTOR CALLED\n";
	try
	{
		if(_grade > 150)
			throw Bureaucrat::GradeTooLowException();
		else if (_grade <= 0)
			throw Bureaucrat::GradeTooHighException();
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	catch(Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy)
{
	std::cout << "BUREAUCRAT COPY CONSTRUCTOR CALLED\n";
	this->Name = copy.Name;
	this->_grade = copy._grade;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "BUREAUCRAT DESTRUCTOR CALLED\n";
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& copy)
{
	std::cout << "BUREAUCRAT ASSIGNMENT OPERATOR CALLED\n";
	if(this == &copy)
		return (*this);
	this->_grade = copy._grade;
	return (*this);
}

void Bureaucrat::incrementGrade()
{
	try
	{
		if((this->_grade - 1) == 0)
		{
			_grade = 1;
			throw GradeTooHighException();
		}
		else
			_grade -= 1;
	}
	catch(Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
		std::cerr << "Grade was updated for the maximum value alowed\n";
	}
}

void Bureaucrat::decrementGrade()
{
	try
	{
		if((this->_grade + 1) > 150)
		{
			_grade = 150;
			throw GradeTooLowException();
		}
		else
			_grade += 1;
	}
	catch(Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
		std::cerr << "Grade was updated for the minimum value alowed\n";
	}
}

std::string Bureaucrat::getName() const
{
	return(this->Name);
}

int Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void Bureaucrat::displayStatus()
{
	std::cout << "BUREAUCRAT--- > " << this->getName() << " has a " << this->getGrade() << " grade\n";
}


std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureu)
{
	return (os << bureu.getName() << ", bureaucrat grade " << bureu.getGrade());
}

void Bureaucrat::signForm(AForm& form)
{
	form.beSigned(*this);
	if (form.getBoolSign() == true)
		std::cout << this->Name << " signed " << form.getName() << std::endl;
	else
		std::cout << this->Name << " couldn't sign " << form.getName() << " because " << "your grade didn't match the expected\n";
}

void Bureaucrat::executeForm(AForm const& form)
{
	bool status = form.execute(*this);
	if (status == false)
		std::cout << "Sorry, " << this->Name << " you were not able to execute " << form.getName() << std::endl;
	else
		std::cout << "Congrats, " << this->Name << " you were able to execute " << form.getName() << std::endl;
}
