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
		
};

#endif
