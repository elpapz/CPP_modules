#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat& copy);
		~Bureaucrat();
		Bureaucrat& operator=(const Bureaucrat& copy);
		void incrementGrade(int value);
		void decrementGrade(int value);
		std::string getName() const;
		int getGrade() const;
		void signForm();
		void displayStatus();
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
		int _grade;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureu);

#endif
