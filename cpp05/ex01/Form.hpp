#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
//#include <iostream>
//class Bureaucrat;

class Form
{
	public:
		Form();
		Form(std::string name, const int sign_grade, const int execute_grade);
		Form(const Form& copy);
		~Form();
		Form &operator=(const Form &copy);
		std::string getName() const;
		const int getSignGrade() const;
		const int getExecuteGrade() const;
		bool getBoolSign() const;
		void beSigned(Bureaucrat &bureau);
		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw()
				{
					return ("Grade is too high!! Maximum grade is 1!");
				}
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw()
				{
					return ("Grade is too low!! Lowest grade is 150");
				}
		};
	private:
		std::string Name;
		bool is_signed;
		const int grade_to_sign;
		const int grade_to_execute;
};

std::ostream& operator<<(std::ostream& os, const Form& copy);

#endif
