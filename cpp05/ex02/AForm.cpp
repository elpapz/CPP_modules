#include "AForm.hpp"

AForm::AForm() : Name("Default Form Name"), is_signed(false), grade_to_sign(42), grade_to_execute(1)
{
	std::cout << "AFORM DEFAULT CONSTRUCTOR CALLED\n";
}
AForm::AForm(std::string name, const int sign_grade, const int execute_grade) : Name(name), is_signed(false), grade_to_sign(sign_grade), grade_to_execute(execute_grade)
{
	std::cout << "AFORM MULTIPLE PARAMETER CONSTRUCTOR CALLED\n";
	try
	{
		if(grade_to_execute > 150 || grade_to_sign > 150)
			throw Bureaucrat::GradeTooLowException();
		else if (grade_to_execute <= 0 || grade_to_sign <= 0)
			throw Bureaucrat::GradeTooHighException();
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << "[AForm]Exception: " << e.what() << std::endl;
	}
	catch(Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << "[AForm]Exception: " << e.what() << std::endl;
	}
}
AForm::AForm(const AForm& copy) : Name(copy.Name), is_signed(copy.is_signed), grade_to_sign(copy.grade_to_sign), grade_to_execute(copy.grade_to_execute)
{
	std::cout << "AFORM COPY CONSTRUCTOR CALLED\n";
	try
	{
		if(grade_to_execute > 150 || grade_to_sign > 150)
			throw Bureaucrat::GradeTooLowException();
		else if (grade_to_execute <= 0 || grade_to_sign <= 0)
			throw Bureaucrat::GradeTooHighException();
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << "[AForm]Exception: " << e.what() << std::endl;
	}
	catch(Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << "[AForm]Exception: " << e.what() << std::endl;
	}
}

AForm::~AForm()
{
	std::cout << "AFORM DECONSTRUCTOR CALLED \n";
}

AForm &AForm::operator=(const AForm &copy)
{
	if(this == &copy)
		return (*this);
	this->is_signed = copy.is_signed;
	return (*this);
}

std::string AForm::getName() const
{
	return(this->Name);
}

int AForm::getSignGrade() const
{
	return (this->grade_to_sign);
}

int AForm::getExecuteGrade() const
{
	return (this->grade_to_execute);
}

bool AForm::getBoolSign() const
{
	return (this->is_signed);
}

void AForm::beSigned(Bureaucrat &bureau)
{
	try
	{
		if(bureau.getGrade() > this->getSignGrade())
			throw AForm::GradeTooLowException();
		else
			this->is_signed = true;
	}
	catch(AForm::GradeTooLowException &e)
	{
		std::cerr << "[AForm]Exception :" << e.what() << std::endl;
	}
	
}

std::ostream& operator<<(std::ostream& os, const AForm& form)
{
	return (os << form.getName() << "-> is signed:" << form.getBoolSign() << " | signed grade:" << form.getSignGrade() << " | execution grade:" << form.getExecuteGrade());
}
