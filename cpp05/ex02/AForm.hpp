#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
class Bureaucrat;

class AForm
{
	public:
		AForm();
		AForm(std::string name, const int sign_grade, const int execute_grade);
		AForm(const AForm& copy);
		~AForm();
		AForm &operator=(const AForm &copy);
		std::string getName() const;
		int getSignGrade() const;
		int getExecuteGrade() const;
		bool getBoolSign() const;
		void beSigned(Bureaucrat &bureau);
		virtual bool execute(Bureaucrat const& executor) const = 0;
		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw()
				{
					return ("Grade is too high!!");
				}
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw()
				{
					return ("Grade is too low!!");
				}
		};
	private:
		const std::string Name;
		bool is_signed;
		const int grade_to_sign;
		const int grade_to_execute;
};

std::ostream& operator<<(std::ostream& os, const AForm& copy);

#endif
