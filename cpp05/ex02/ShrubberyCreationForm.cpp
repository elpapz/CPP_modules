#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string const& target) : AForm("Shrurbbery", 145, 137), _target(target){
	std::cout << "SHRUBBERY CONSTRUCTOR CALLED\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& form) : AForm(form), _target(form._target){
	std::cout << "SHRUBBERY COPY CONSTRUCTOR CALLED\n";
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
	std::cout << "SHRUBBERY DECONSTRUCTOR CALLED\n";
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const& form)
{
	std::cout << "SHRUBBERY ASSIGNMENT OPERATOR CALLED\n";
	if (this == &form)
		return(*this);
	AForm::operator=(form);
	//this->_target = form._target;
	return(*this);
}

std::string const& ShrubberyCreationForm::getTarget() const
{
	return(this->_target);
}

bool ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
	try
	{
		if (this->getBoolSign() == true)
		{
			if (executor.getGrade() < this->getExecuteGrade())
			{
				std::ofstream file;
				std::string file_name = _target + "_shrubbery";
				file.open(file_name.c_str(), std::ios::in | std::ios::trunc);
				if (!file.is_open())
				{
					std::cout << "Failed to open the file";
					return (false);
				}
				else
				{
					file << "     *     \n"
						 << "    * *\n"
						 << "   * * *\n"
						 << "  ** || *\n";
					std::cout << "THE TREES ARE DRAWN IN THE FILE, GO CHECK IT OUT\n";
				}
				file.close();
			}
			else
			{
				std::cout << executor.getName() << " GRADE IS TOO LOW TO EXECUTE CREATION FORM\n";
				throw AForm::GradeTooLowException();
			}
		}
		else
		{
			std::cout << "SHRUBBERY FORM NOT SIGNED\n";
			return false;
		}
	}
	catch(GradeTooLowException &e)
	{
		std::cerr << "[SHRUBBERY]Exception :" << e.what() << std::endl;
		return false;
	}
return (true);
}
