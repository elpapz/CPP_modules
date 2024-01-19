#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

// int main(void)
// {
//     PresidentialPardonForm president("Target_President");
//     RobotomyRequestForm robotomy("Target_Robotomy");
//     ShrubberyCreationForm shrubbery("Target_Shrubbery");
//     Bureaucrat Andre("Andre", 50);

//     president.beSigned(Andre);
//     president.execute(Andre);

//     robotomy.beSigned(Andre);
//     robotomy.execute(Andre);

//     shrubbery.beSigned(Andre);
//     shrubbery.execute(Andre);

//     Andre.executeForm(president);
//     Andre.executeForm(robotomy);
//     Andre.executeForm(shrubbery);
// }

int main()
{
    Bureaucrat b1("Jany", 24);
    PresidentialPardonForm presidential("target1");
    RobotomyRequestForm robotomy("target2");
    ShrubberyCreationForm shrubbery("target3");

    presidential.beSigned(b1);
    presidential.execute(b1);

    robotomy.beSigned(b1);
    robotomy.execute(b1);

    shrubbery.beSigned(b1);
    shrubbery.execute(b1);

    b1.executeForm(presidential);
    b1.executeForm(shrubbery);
}
