#include "Form.hpp"

Form::Form() : Name("Default Form Name"), is_signed(false), grade_to_sign(42), grade_to_execute(1)
{
	std::cout << "FORM DEFAULT CONSTRUCTOR CALLED\n";
}
Form::Form(std::string name, const int sign_grade, const int execute_grade) : Name(name), grade_to_sign(sign_grade), grade_to_execute(execute_grade), is_signed(false)
{
	std::cout << "MULTIPLE PARAMETER CONSTRUCTOR CALLED\n";
}
Form::Form(const Form& copy) : Name(copy.Name), grade_to_sign(copy.grade_to_sign), grade_to_execute(copy.grade_to_execute), is_signed(copy.is_signed)
{
	std::cout << "FORM COPY CONSTRUCTOR CALLED\n";
	try
	{
		if(grade_to_execute > 150 || grade_to_sign > 150)
			throw Bureaucrat::GradeTooLowException();
		else if (grade_to_execute <= 0 || grade_to_sign <= 0)
			throw Bureaucrat::GradeTooHighException();
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << "[Form]Exception: " << e.what() << std::endl;
	}
	catch(Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << "[Form]Exception: " << e.what() << std::endl;
	}
}

Form::~Form()
{
	std::cout << "FORM DECONSTRUCTOR CALLED \n";
}

Form &Form::operator=(const Form &copy)
{
	if(this == &copy)
		return (*this);
	this->is_signed = copy.is_signed;
}

std::string Form::getName() const
{
	return(this->Name);
}

const int Form::getSignGrade() const
{
	return (this->grade_to_sign);
}

const int Form::getExecuteGrade() const
{
	return (this->grade_to_execute);
}

bool Form::getBoolSign() const
{
	return (this->is_signed);
}

void Form::beSigned(Bureaucrat &bureau)
{
	try
	{
		if(bureau.getGrade() > this->getSignGrade())
			throw Form::GradeTooLowException();
		else
			this->is_signed = true;
	}
	catch(Form::GradeTooLowException &e)
	{
		std::cerr << "[Form]Exception :" << e.what() << std::endl;
	}
	
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
	return (os << form.getName() << ", is signed: " << form.getBoolSign() << " signed grade :" << form.getSignGrade() << " execution grade: " << form.getExecuteGrade());
}
