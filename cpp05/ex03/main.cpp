#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main()
{
    Intern someRandomIntern;
    Bureaucrat Andre("Andre", 140);
    AForm *paperwork = someRandomIntern.makeForm("robotomy request", "terrorist");
    if (!paperwork)
        return 0;
    Andre.signForm(*paperwork);
    Andre.executeForm(*paperwork);
    delete paperwork;
}
